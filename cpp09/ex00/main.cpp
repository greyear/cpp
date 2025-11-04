
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Program should take one argument: input file with a database" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange bit;
		bit.exchange(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}