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
	const char*	type;
	std::regex	pattern;
	std::function<void(const std::string&)> handlerFunction;
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

int ScalarConverter::afterDot(const std::string& str)
{
	size_t dot = str.find('.'); //check 2 dots
	if (dot == std::string::npos)
		return 1;
	
	size_t end = str.find('f', dot);
	if (end == std::string::npos)
		end = str.length();
	
	size_t digitsAfterDot = end - dot - 1;
	std::cout << "digits after dot: " << digitsAfterDot << std::endl; //delete
	if (digitsAfterDot == 0 || digitsAfterDot > static_cast<size_t>(std::numeric_limits<int>::max()))
		return 1;
	return static_cast<int>(digitsAfterDot);
}

void ScalarConverter::handleChar(const std::string& str)
{

}

void ScalarConverter::handleInt(const std::string& str)
{

}

void ScalarConverter::handleFloat(const std::string& str)
{

}

void ScalarConverter::handleDouble(const std::string& str)
{

}

void ScalarConverter::handleSpecial(const std::string& str)
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

void ScalarConverter::printChar(char c)
{
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{

}

void ScalarConverter::printDouble(double d)
{

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
		{"float", std::regex(R"(^[-+]?((\d+\.\d*)|(\d*\.\d+)|\d+)f$)"), handleFloat}, 
		{"double", std::regex(R"(^[-+]?((\d+\.\d*)|(\d*\.\d+))$)"), handleDouble},
		{"special", std::regex(R"(^([-+]?(inf|nan)f?$)"), handleSpecial}
	};
	
	for (const Handler& handler : handlers)
	{
		if (std::regex_match(str, handler.pattern))
		{
			try
			{
				{
					handler.handlerFunction(str);
					return ;
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n'; //?
				printImpossible();
				return ;
			}
			
		}
	}
	printImpossible();
}

/*
1) Лямбды (Lambdas:
функции, которые можно создавать прямо в коде. 
могут захватывать переменные из окружения.
[capture](parameters) { body }


*/