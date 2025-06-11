
#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "./harlFilter should have exactly 1 argument" << std::endl;
		return (0);
	}

	Harl	harl;
	harl.switchLevels(argv[1]);

	return (0);
}