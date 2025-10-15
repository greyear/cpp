/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:02:57 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 21:02:59 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <cmath>
#include <limits>
#include <functional>

#define MAX_PRECISION 10

class ScalarConverter
{
	private:
		static int	afterDot(const std::string& str);
		static void	printChar(char c);
		static void	printInt(int i);
		static void	printFloat(float f, int afterDot);
		static void	printDouble(double d, int afterDot);
		static void	printImpossible();
		static void handleChar(const std::string& str, int afterDot);
		static void handleInt(const std::string& str, int afterDot);
		static void handleFloat(const std::string& str, int afterDot);
		static void handleDouble(const std::string& str, int afterDot);
		static void handleSpecial(const std::string& str, int afterDot);
	public:
		ScalarConverter() = delete;
		~ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;

		static void convert(const std::string& str);
};
