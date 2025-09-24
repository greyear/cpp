/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:03:27 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 21:03:29 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

struct Handler
{
    std::string type;
    std::regex pattern;
    void (*handlerFunction)(const std::string&);
};

/*
regex:
^ means start of the line
$ end of the line
? means 0 or 1 time
| means OR
d+ means 1 or more digits
R"" raw string literal (not to have 2 \\)

char: std::regex(R"(^[\x20-\x7E]$)") - from space to tilde, only 1 symbol
int: std::regex(R"(^[-+]?\d+$)") - 
float: std::regex(R"(^[-+]?\d+\.\d+f$)") - 
double: std::regex(R"(^[-+]?\d+\.\d+$)") -
special: std::regex(R"(^[-+]?inff?$|^nanf?$)") - 
*/

void handleChar(const std::string& str)
{

}

void handleInt(const std::string& str)
{

}

void handleFloat(const std::string& str)
{

}

void handleDouble(const std::string& str)
{

}

void handleSpecial(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	if (str == "nan" || str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void ScalarConverter::printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
	Handler handlers[] = 
	{
		{"char", std::regex(R"(^[\x20-\x7E]$)"), handleChar},
		{"int", std::regex(R"(^[-+]?\d+$)"), handleInt}, 
		{"float", std::regex(R"(^[-+]?\d+\.\d+f$)"), handleFloat}, 
		{"double", std::regex(R"(^[-+]?\d+\.\d+$)"), handleDouble},
		{"special", std::regex(R"(^[-+]?inff?$|^nanf?$)"), handleSpecial}
	}
	...
}