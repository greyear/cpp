/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:23:11 by azinchen          #+#    #+#             */
/*   Updated: 2025/11/05 15:23:13 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::exchange(char *inputFile)
{
	fillDateRateMap();
	handleValuesInput(inputFile);
}

bool BitcoinExchange::isLeapYear(int y)
{
	if (y % 400 == 0)
		return true;
	else if (y % 100 == 0)
		return false;
	else if (y % 4 == 0)
		return true;
	else
		return false;  
}

bool BitcoinExchange::isExistingDate(int y, int m, int d)
{
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (y < 2009)
		return false;
	if (m < 1 || m > 12)
		return false;
	int dayLimit = daysInMonth[m - 1];
	if (m == 2 && isLeapYear(y) == true)
		dayLimit = 29;
	if (d < 1 || d > dayLimit)
		return false;
	return true;
}

std::string BitcoinExchange::getToday()
{
	std::time_t t = std::time(nullptr); //current time in sec since 1970-01-1
	std::tm tm = *std::localtime(&t); //date data struct
	std::ostringstream oss; //stream variable
	oss << std::put_time(&tm, "%Y-%m-%d"); //formatted
	return oss.str();
}

void BitcoinExchange::fillDateRateMap()
{
	std::ifstream inputFile("./data.csv");
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open data.csv file.");

	std::string line;
	std::getline(inputFile, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: invalid data.csv file (header bad format).");
	
	std::regex linePattern(R"(^(\d{4})-(\d{2})-(\d{2}),(\d+(?:\.\d+)?)$)");
	std::smatch match;
	while (std::getline(inputFile, line))
	{
		if (std::regex_match(line, match, linePattern))
		{
			int year = std::stoi(match[1].str());
			int month = std::stoi(match[2].str());
			int day = std::stoi(match[3].str());
			if (!isExistingDate(year, month, day))
			{
				std::cout << "Error: invalid date in data.csv: " << line << std::endl;
				continue;
			}
			std::string yMD = match[1].str() + "-" + match[2].str() + "-" + match[3].str();
			double rate;
			try
			{
				rate = std::stod(match[4].str());
			}
			catch(const std::exception& e)
			{
				std::cout << "Error: invalid exchange rate in data.csv: " << line << std::endl;
				continue;
			}

			if (_datePrices.find(yMD) != _datePrices.end())
			{
				std::cout << "Error: duplicate dates in data.csv: " << line << std::endl;
				continue;
			}
			_datePrices[yMD] = rate;
		}
		else
		{
			std::cout << "Error: invalid line in data.csv file: " << line << std::endl;
			continue;
		}
	}
	if (_datePrices.empty())
		throw std::runtime_error("Error: data.csv is empty or contains no valid entries");
	if (_datePrices.rbegin()->first > getToday())
		std::cout << "Error: there's a future date in data.csv file" << std::endl;
}

double BitcoinExchange::getPrice(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _datePrices.find(date);
	if (it != _datePrices.end())
		return it->second;
	it = _datePrices.lower_bound(date);
	if (it == _datePrices.begin())
		throw std::runtime_error("Error: there's no exchange rate in database (all dates are upper ones, but we needed the lower date!)");
	--it;
	return it->second;
}

void BitcoinExchange::handleValuesInput(char *filePath)
{
	std::ifstream inputFile(filePath);
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::string line;
	std::getline(inputFile, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid input file (header bad format).");

	std::regex linePattern(R"(^(\d{4})-(\d{2})-(\d{2}) \| ([-+]?\d+(?:\.\d+)?)$)");
	std::smatch match;
	while (std::getline(inputFile, line))
	{
		if (line.empty())
			continue;
		if (std::regex_match(line, match, linePattern))
		{
			int year = std::stoi(match[1].str());
			int month = std::stoi(match[2].str());
			int day = std::stoi(match[3].str());
			if (!isExistingDate(year, month, day))
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			std::string yMD = match[1].str() + "-" + match[2].str() + "-" + match[3].str();
			if (yMD > getToday())
			{
				std::cout << "Error: there's a future date in input file" << std::endl;
				continue;
			}

			double amount;
			try
			{
				amount = std::stod(match[4].str());
			}
			catch(const std::exception& e)
			{
				std::cout << "Error: invalid amount. " << std::endl;
				continue;
			}
			if (amount < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			if (amount > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}

			try
			{
				double price = getPrice(yMD);
				double mult = amount * price;
				std::cout << yMD << " => " << amount << " = " << mult << std::endl;	
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
	}
}
