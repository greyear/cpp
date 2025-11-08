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
#include <bits/stdc++.h> //delete

PmergeMe::PmergeMe(int argc, char *argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		std::string argStr(argv[i]);
		int argInt;

		if (!ifOnlyPositiveInts(argStr))
			throw std::runtime_error("Error: invalid argument: " + argStr);
		argInt = std::stoi(argStr);
		_vecNums.push_back(argInt);
		_deqNums.push_back(argInt);
	}
}

void PmergeMe::run()
{
	printContainer("Before:\t", _vecNums);
	auto startTime = std::chrono::high_resolution_clock::now();
	sortVector(_vecNums);
	auto endTime = std::chrono::high_resolution_clock::now();
	_runTimeVector = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	printContainer("After:\t", _vecNums);

	startTime = std::chrono::high_resolution_clock::now();
	sortDeque(_deqNums);
	endTime = std::chrono::high_resolution_clock::now();
	_runTimeDeque = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	printContainer("After:\t", _deqNums); //delete

	std::cout << "Time to process a range of " << _vecNums.size() << " elements with std::vector : " << _runTimeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _deqNums.size() << " elements with std::deque : " << _runTimeDeque << " us" << std::endl;
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

bool comp(int a, int b) //delete
{
    return a < b;
}

void PmergeMe::sortVector(std::vector<int>& v)
{
	sort(v.begin(), v.end(), comp);
}

void PmergeMe::sortDeque(std::deque<int>& d)
{
	sort(d.begin(), d.end(), comp);
}


