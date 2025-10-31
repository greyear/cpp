
#pragma once

#include <map>
#include <string>
#include <fstream>
#include <regex>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _dateRate;

        void fillDateRateMap();
        bool isValidDate(const std::string& date);
    public:
        BitcoinExchange() = default;
        BitcoinExchange(const BitcoinExchange& other) = delete;
        BitcoinExchange& operator=(const BitcoinExchange& other) = delete;
        ~BitcoinExchange() = default;

        void exchange(char *inputFile);
};





/*
1st - we have 2 files: date+rate (double), date+value. we need to print date+value*rate
    -map (date, rate)

2nd - we need to store all figures and signs from argv (with duplicates)
    -stack

3rd - we need to store a lot of ints to sort (with duplicates)
    -vector + deque/list
*/
