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
d* means 0 or more digits
R"" raw string literal (not to have 2 \\)
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
	if (digitsAfterDot == 0)
		return 1;
	else if (digitsAfterDot > MAX_PRECISION)
		digitsAfterDot = MAX_PRECISION;
	return static_cast<int>(digitsAfterDot);
}

void ScalarConverter::handleChar(const std::string& str)
{
	char c = str[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::handleInt(const std::string& str)
{
	long long temp = std::stoll(str);

	if (temp >= -128 && temp <= 127)
		printChar(static_cast<char>(temp));
	else
		std::cout << "char: impossible" << std::endl;

	if (temp >= std::numeric_limits<int>::min() && temp <= std::numeric_limits<int>::max())
		printInt(static_cast<int>(temp));
	else
		std::cout << "int: impossible" << std::endl;
	
	printFloat(static_cast<float>(temp));
	printDouble(static_cast<double>(temp));
}

void ScalarConverter::handleFloat(const std::string& str)
{
	float f = std::stof(str);

	if (f >= -128 && f <= 127)
		printChar(static_cast<char>(f));
	else
		std::cout << "char: impossible" << std::endl;

	double d = static_cast<double>(f);
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		printInt(static_cast<int>(f));
	else
		std::cout << "int: impossible" << std::endl;
	
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::handleDouble(const std::string& str)
{
	double d = std::stod(str);

	if (d >= -128 && d <= 127)
		printChar(static_cast<char>(d));
	else
		std::cout << "char: impossible" << std::endl;

	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		printInt(static_cast<int>(d));
	else
		std::cout << "int: impossible" << std::endl;
	
	//lowest, but not MIN (as MIN is a positive number!)
	if (d >= std::numeric_limits<float>::lowest() && d <= std::numeric_limits<float>::max())
		printFloat(static_cast<float>(d));
	else
		std::cout << "float: impossible" << std::endl;

	printDouble(d);
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
	if (f == std::numeric_limits<float>::infinity())
		std::cout << "float: +inff" << std::endl;
	else if (f == -std::numeric_limits<float>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (std::isnan(f))
		std::cout << "float: nan" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	if (d == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
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
		{"special", std::regex(R"(^[-+]inff$|^[-+]inf$|^nanf$|^nan$)"), handleSpecial}
	};
	for (const Handler& handler : handlers)
	{
		if (std::regex_match(str, handler.pattern))
		{
			try
			{
				{
					int digitsAfter = afterDot(str);
					std::cout << "digits after dot: " << digitsAfter << std::endl; //delete
					handler.handlerFunction(str);
					return ;
				}
			}
			catch (const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl; //?
				printImpossible();
				return ;
			}
			catch (...)
			{
				printImpossible();
				return ;
			}
		}
	}
	printImpossible();
}
