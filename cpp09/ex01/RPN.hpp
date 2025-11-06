/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:40:24 by azinchen          #+#    #+#             */
/*   Updated: 2025/11/05 15:40:28 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <limits>

class RPN
{
	private:
		std::stack<long long> _st;

		bool isOperator(char c);
		long long calculate(long long a, long long b, char c);
	public:
		RPN() = default;
		RPN(const RPN& other) = delete;
		RPN& operator=(const RPN& other) = delete;
		~RPN() = default;

		void countRPN(const std::string& arg);
};

/*


*/