/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:24:04 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/28 13:24:06 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_num;
	public:
		Span() = delete;
		Span(unsigned int n);
		Span(const Span& other) = default;
		Span& operator=(const Span& other) = default;
		~Span() = default;

		void addNumber(int newNum);
		void addNumber(const std::vector<int>& v);
		void addNumber(std::vector<int>::const_iterator b, std::vector<int>::const_iterator e);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};
