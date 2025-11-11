/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:51:21 by azinchen          #+#    #+#             */
/*   Updated: 2025/11/06 16:51:22 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int> _vecNums;
		std::deque<int>	_deqNums;
		std::chrono::microseconds _runTimeVector;
		std::chrono::microseconds _runTimeDeque;

		bool ifOnlyPositiveInts(const std::string& str);

		/*void sortVector(std::vector<int>& v);
		void sortDeque(std::deque<int>& d);*/
	public:
		PmergeMe() = delete;
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe& other) = delete;
		PmergeMe& operator=(const PmergeMe& other) = delete;
		~PmergeMe() = default;

		void run();
};

template <typename T>
void insertBinary(T& cont, int value)
{
	typename T::iterator it = std::lower_bound(cont.begin(), cont.end(), value);
	cont.insert(it, value);
}

template <typename T>
void printContainer(const std::string& phrase, const T& cont)
{
	std::cout << phrase;
	bool first = true;
	for (const auto& num : cont)
	{
		if (!first)
			std::cout << " ";
		std::cout << num;
		first = false;
	}
	std::cout << std::endl;
}

std::vector<size_t>	jacobsthalIndexesInNElements(size_t n);

template <typename T>
void sortFordJohnson(T& cont)
{
	//part 1: pairing, putting into 2 containers
	if (cont.size() == 0 || cont.size() == 1)
		return;

	T mainChain;
	T toInsert;
	size_t i;
	for (i = 0; i < cont.size() - 1; i += 2)
	{
		if (cont[i] >= cont[i + 1])
		{
			mainChain.push_back(cont[i]);
			toInsert.push_back(cont[i + 1]);
		}
		else
		{
			mainChain.push_back(cont[i + 1]);
			toInsert.push_back(cont[i]);
		}
	}
	if (i < cont.size()) //odd size, last element has no pair
		toInsert.push_back(cont[i]);

	//part 2: recursion for mainChain
	sortFordJohnson(mainChain);
	T copy = mainChain;

	//std::cout << "size of mainChain is " << mainChain.size() << ", and of toInsert is " << toInsert.size() << std::endl;

	//part 3: which ones to insert first (Jacobsthal indexes)
	std::vector<size_t> jacobIndexes = jacobsthalIndexesInNElements(toInsert.size());
	std::vector<bool> alreadyInserted(toInsert.size(), false);
	for (size_t j = 0; j < jacobIndexes.size(); ++j)
	{
		size_t jInd = jacobIndexes[j];
		if (!alreadyInserted[jInd])
		{
			insertBinary(copy, toInsert[jInd]);
			alreadyInserted[jInd] = true;
		}
	}

	//part 4: binary search for inserting others
	for (size_t k = 0; k < toInsert.size(); ++k)
	{
		if (!alreadyInserted[k])
		{
			insertBinary(copy, toInsert[k]);
			alreadyInserted[k] = true;
		}
	}

	cont = copy;
}