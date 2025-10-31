
#include "BitcoinExchange.hpp"

void BitcoinExchange::exchange(char *inputFile)
{
    fillDateRateMap();
    
}

void BitcoinExchange::fillDateRateMap()
{
    std::ifstream inputFile("./data.csv");
    if (!inputFile.is_open())
        throw std::runtime_error("Could not open data.csv file.");

    std::string line;
    std::getline(inputFile, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("Invalid data.csv file (header bad format).");
    
    std::regex linePattern()
    while (std::getline(inputFile, line))
    {

    }
}
