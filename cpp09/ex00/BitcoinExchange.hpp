/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:23:19 by azinchen          #+#    #+#             */
/*   Updated: 2025/11/05 15:23:20 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <fstream>
#include <regex>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _datePrices;

		bool isLeapYear(int y);
		bool isExistingDate(int y, int m, int d);
		std::string getToday();
		void fillDateRateMap();
		double getPrice(const std::string& date) const;
		void handleValuesInput(char *filePath); //static??
	public:
		BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange& other) = delete;
		BitcoinExchange& operator=(const BitcoinExchange& other) = delete;
		~BitcoinExchange() = default;

		void exchange(char *inputFile);
};
