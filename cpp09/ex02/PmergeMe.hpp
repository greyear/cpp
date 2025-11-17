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
#include <utility>

static size_t g_comparisonCount = 0;

template<typename T>
bool cmp_less(const T& a, const T& b) {
    ++g_comparisonCount;
    return a < b;
}

template<typename T>
bool cmp_greater_or_equal(const T& a, const T& b) {
    ++g_comparisonCount;
    return a >= b;
}

template<typename It, typename T>
It upper_bound_counting(It begin, It end, const T& value) {
    It left = begin;
    It right = end;

    while (left < right) {
        It mid = left + (std::distance(left, right) / 2);
        if (!cmp_less(value, *mid))  // value >= *mid → go right
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

//delete!



class PmergeMe
{
	private:
		std::vector<int> _vecNums;
		std::deque<int>	_deqNums;
		std::chrono::microseconds _runTimeVector;
		std::chrono::microseconds _runTimeDeque;
		bool ifOnlyPositiveInts(const std::string& str);
	public:
		PmergeMe() = delete;
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe& other) = delete;
		PmergeMe& operator=(const PmergeMe& other) = delete;
		~PmergeMe() = default;
		void run();
};

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

template <typename T>
typename T::iterator findUnused(T& copy, const std::vector<bool>& used, int target)
{
	for (auto it = copy.begin(); it != copy.end(); ++it)
	{
		auto ind = std::distance(copy.begin(), it);
		if (*it == target && used[ind] == false)
			return it;
	}
	return (copy.end());
}

std::vector<size_t>	jacobsthalIndexesInNElements(size_t n);

template <typename T>
void sortFordJohnson(T& cont)
{
	if (cont.size() <= 1)
		return;

	T mainChain;
	T toInsert;
	std::vector<std::pair<int, int>> pairs;

	//pairing
	size_t i;
	for (i = 0; i + 1 < cont.size(); i += 2)
	{
		if (cmp_greater_or_equal(cont[i], cont[i + 1])) //if (cont[i] >= cont[i + 1]) delete!
			pairs.push_back(std::make_pair(cont[i], cont[i + 1]));
		else
			pairs.push_back(std::make_pair(cont[i + 1], cont[i]));
	}
	bool hasLonely = false;
	int lonely;
	if (i < cont.size())
	{
		hasLonely = true;
		lonely = cont[i];
	}
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		mainChain.push_back(pairs[j].first);
		toInsert.push_back(pairs[j].second);
	}

	//recursion
	sortFordJohnson(mainChain);

	//checking bigger element's from pair position in sorted mainChain
	T copy = mainChain;
	std::vector<size_t> aPositions(pairs.size());
	std::vector<bool> used(copy.size(), false);

	for (size_t j = 0; j < pairs.size(); ++j)
	{
		auto it = findUnused(copy, used, pairs[j].first);
		if (it == copy.end())
			throw std::logic_error("element is not found in mainChain");
		size_t pos = static_cast<size_t>(std::distance(copy.begin(), it));
		aPositions[j] = pos;
		used[pos] = true;
	}

	//inserting jacobsthal index elements
	std::vector<size_t> jacobIndexes = jacobsthalIndexesInNElements(toInsert.size());
	std::vector<bool> alreadyInserted(toInsert.size(), false);

	for (size_t j = 0; j < jacobIndexes.size(); ++j)
	{
		size_t jInd = jacobIndexes[j];
		if (jInd >= toInsert.size() || alreadyInserted[jInd])
			continue;
		size_t limit = aPositions[jInd];
		auto it = upper_bound_counting(copy.begin(), copy.begin() + limit, toInsert[jInd]);
		//auto it = std::upper_bound(copy.begin(), copy.begin() + limit, toInsert[jInd]); change
		size_t insertedPos = static_cast<size_t>(std::distance(copy.begin(), it));
		copy.insert(it, toInsert[jInd]);
		alreadyInserted[jInd] = true;
		for (size_t k = 0; k < aPositions.size(); ++k)
		{
			if (aPositions[k] >= insertedPos)
				++aPositions[k];
		}
	}

	//inserting others
	for (size_t k = 0; k < toInsert.size(); ++k)
	{
		if (!alreadyInserted[k])
		{
			size_t limit = aPositions[k];
			auto it = upper_bound_counting(copy.begin(), copy.begin() + limit, toInsert[k]);
			//auto it = std::upper_bound(copy.begin(), copy.begin() + limit, toInsert[k]);
			size_t insertedPos = static_cast<size_t>(std::distance(copy.begin(), it));
			copy.insert(it, toInsert[k]);
			alreadyInserted[k] = true;
			for (size_t m = 0; m < aPositions.size(); ++m)
			{
				if (aPositions[m] >= insertedPos)
					++aPositions[m];
			}
		}
	}

	//if there was a lonely element (odd number of elements)
	if (hasLonely)
	{
		auto it = upper_bound_counting(copy.begin(), copy.end(), lonely);
		//auto it = std::upper_bound(copy.begin(), copy.end(), lonely);
		copy.insert(it, lonely);
	}

	cont = copy;
}
