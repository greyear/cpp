/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:51:12 by azinchen          #+#    #+#             */
/*   Updated: 2025/11/06 16:51:14 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		std::string argStr(argv[i]);
		int argInt;

		if (!ifOnlyPositiveInts(argStr))
			throw std::runtime_error("Error: invalid argument: " + argStr);
		try
		{
			argInt = std::stoi(argStr);
		}
		catch (const std::out_of_range& e)
		{
			throw std::runtime_error("Error: number is too large: " + argStr);
		}
		catch (const std::invalid_argument& e)
		{
			throw std::runtime_error("Error: invalid number: " + argStr);
		}

		_vecNums.push_back(argInt);
		_deqNums.push_back(argInt);
	}
}

void PmergeMe::run()
{
	printContainer("Before:\t", _vecNums);
	auto startTime = std::chrono::high_resolution_clock::now();
	//sortFordJohnson(_vecNums);
	g_comparisonCount = 0;
	sortFordJohnson(_vecNums);
	std::cout << "Comparisons for vector: " << g_comparisonCount << std::endl;

	auto endTime = std::chrono::high_resolution_clock::now();
	_runTimeVector = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	printContainer("After:\t", _vecNums);

	startTime = std::chrono::high_resolution_clock::now();
	//sortFordJohnson(_deqNums);
	g_comparisonCount = 0;
	sortFordJohnson(_deqNums);
	std::cout << "Comparisons for deque: " << g_comparisonCount << std::endl;


	endTime = std::chrono::high_resolution_clock::now();
	_runTimeDeque = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

	std::cout << "Time to process a range of " << _vecNums.size() << " elements with std::vector : " << _runTimeVector.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << _deqNums.size() << " elements with std::deque : " << _runTimeDeque.count() << " us" << std::endl;
}

bool PmergeMe::ifOnlyPositiveInts(const std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

std::vector<size_t> jacobsthalIndexesInNElements(size_t n)
{
	std::vector<size_t> jac;
	if (n == 0)
		return jac;

	jac.push_back(0);
	if (n == 1)
		return jac;

	jac.push_back(1);
	while (jac.back() < n)
	{
		jac.push_back((jac[jac.size() - 1] + 2 * jac[jac.size() - 2]));
	}

	if (jac.back() >= n)
		jac.pop_back();

	return jac;
}
