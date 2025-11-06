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

	if (arg.empty())
		throw std::runtime_error("Error: invalid expression");
	while (iss >> token)
	{
		if (token.length() != 1)
			throw std::runtime_error("Error: invalid token: " + token);
		else if (isdigit(token[0]))
			_st.push(std::stoll(token));
		else if (isOperator(token[0]))
		{
			if (_st.size() < 2)
				throw std::runtime_error("Error: invalid expression");
			else
			{
				long long a = _st.top();
				_st.pop();
				long long b = _st.top();
				_st.pop();
				long long c = calculate(a, b, token[0]);
				_st.push(c);
			}
		}
		else
			throw std::runtime_error("Error: invalid token: " + token);
	}

	if (_st.size() != 1)
		throw std::runtime_error("Error: invalid expression");

	long long res = _st.top();
	std::cout << res << std::endl;
}

bool RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

long long RPN::calculate(long long a, long long b, char c)
{
	long long res;

	switch(c)
	{
		case '+':
			res = b + a;
			break;
		case '-':
			res = b - a;
			break;
		case '*':
			res = b * a;
			break;
		case '/':
		{
			if (a == 0)
				throw std::runtime_error("Error: division by zero!");
			res = b / a;
			break;
		}
		default:
			throw std::runtime_error("Error: unknown operator"); 
	}
	if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max())
		throw std::runtime_error("Error: int overflow reached");
	return (res);
}


