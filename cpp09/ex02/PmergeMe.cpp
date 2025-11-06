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
	for (size_t i = 0; i < argc; ++i)
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
	//measuring time and executing
	auto startTime = std::chrono::high_resolution_clock::now();
	
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