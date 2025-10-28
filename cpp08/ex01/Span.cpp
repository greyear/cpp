/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:23:46 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/28 13:23:48 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): _N(n), _num()
{
	_num.reserve(n);
}

void Span::addNumber(int newNum)
{
	if (_num.size() >= _N)
		throw std::length_error("Max amount of numbers is reached, cannot add more");
	_num.push_back(newNum);
}

unsigned int Span::shortestSpan() const
{
	if (_num.size() <= 1)
		throw std::logic_error("Not enough numbers to look for a span");
	std::vector<int> sortNum = _num;
	std::sort(sortNum.begin(), sortNum.end());
	unsigned int res = std::numeric_limits<unsigned int>::max();
	for (std::size_t i = 1; i < sortNum.size(); ++i)
	{
		unsigned int diff = static_cast<unsigned int>(static_cast<long long>(sortNum[i]) - static_cast<long long>(sortNum[i - 1]));
		if (diff < res)
			res = diff;
	}
	return (res);
}

unsigned int Span::longestSpan() const
{
	if (_num.size() <= 1)
		throw std::logic_error("Not enough numbers to look for a span");
	auto minMaxPair = std::minmax_element(_num.begin(), _num.end());
	unsigned int res = static_cast<unsigned int>(static_cast<long long>(*minMaxPair.second) - static_cast<long long>(*minMaxPair.first));
	return (res);
}
