
#include "Harl.hpp"

Harl::Harl()
{

}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
			"pickle-special-ketchup burger. I really do!" << '\n';
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money."
			"\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t"
			" be asking for more!" << '\n';
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free."
			<< "\nI’ve been coming for years whereas you started working here since"
			" last month." << '\n';
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager"
			" now." << '\n';
}

void	Harl::complain( std::string level )
{
	const std::string commentLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (commentLevels[i] == level)
		{
			std::cout << "[ " << level << " ]" << std::endl;
			(this->*functions[i])();
			std::cout << std::endl;
			return ;
		}
	}
}

int	Harl::filterLevelsAbove( std::string level )
{
	const std::string commentLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (commentLevels[i] == level)
			return (i + 1);
	}
	return (0);
}

void	Harl::switchLevels( std::string level )
{
	switch (filterLevelsAbove(level))
	{
		case 1:
		{
			complain("DEBUG");
			[[fallthrough]];
		}
		case 2:
		{
			complain("INFO");
			[[fallthrough]];
		}
		case 3:
		{
			complain("WARNING");
			[[fallthrough]];
		}
		case 4:
		{
			complain("ERROR");
			break ;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
}
