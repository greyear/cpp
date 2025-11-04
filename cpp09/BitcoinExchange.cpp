
#include "BitcoinExchange.hpp"

void BitcoinExchange::exchange(char *inputFile)
{
    fillDateRateMap();
    handleValuesInput(char *filePath);
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
        throw std::runtime_error("Could not open data.csv file.");

    std::string line;
    std::getline(inputFile, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("Invalid data.csv file (header bad format).");
    
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
                throw std::runtime_error("Invalid date in data.csv: " + line);
            std::string yMD = match[1].str() + "-" + match[2].str() + "-" + match[3].str();
            double rate = std::stod(match[4].str());
            if (_dateRate.find(yMD) != _dateRate.end())
                throw std::runtime_error("Duplicate dates in data.csv");
            _dateRate[yMD] = rate;
        }
        else
            throw std::runtime_error("Invalid line in data.csv file: " + line);
    }
    inputFile.close();
    if (_dateRate.empty())
        throw std::runtime_error("There's no valid data in data.csv file");
    if (_dateRate.rbegin()->first > getToday())
        throw std::runtime_error("There's a future date in data.csv file");
}

void BitcoinExchange::handleValuesInput(char *filePath)
{
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open())
        throw std::runtime_error("Could not open input file.");

    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value")
        throw std::runtime_error("Invalid input file (header bad format).");

    std::regex linePattern(R"(^(\d{4})-(\d{2})-(\d{2}) \| ([+]?\d+(?:\.\d+)?)$)");
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
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            std::string yMD = match[1].str() + "-" + match[2].str() + "-" + match[3].str();
            double rate = std::stod(match[4].str());
            if (_dateRate.find(yMD) != _dateRate.end())
                throw std::runtime_error("Duplicate dates in data.csv");
            _dateRate[yMD] = rate;
        }
        else
            throw std::runtime_error("Invalid line in input file: " + line);
    }

}