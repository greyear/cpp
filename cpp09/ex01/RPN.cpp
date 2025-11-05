/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:40:17 by azinchen          #+#    #+#             */
/*   Updated: 2025/11/05 15:40:18 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN::countRPN(const std::string& arg)
{
	std::istringstream iss(arg);
	std::string token;

	while (iss >> token)
	{
		
	}
}

bool RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

long long RPN::calculate(long long a, long long b, char c)
{
	switch(c)
	{
		case '+':
			return b + a;
		case '-':
			return b - a;
		case '*':
			return b * a;
		case '/':
		{
			if (a == 0)
				throw std::runtime_error("Error: division by zero!"); // type of exception?
			return b / a;
		}
		default:
			throw std::runtime_error("Error: unknown operator"); 
	}
}


