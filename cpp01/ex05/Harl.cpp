/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:41:22 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/10 21:41:24 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

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
			" You didn’t put enough bacon in my burger! If you did, I wouldn’t"
			" be asking for more!" << '\n';
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve"
			" been coming for years whereas you started working here since"
			" last month." << '\n';
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager"
			" now." << '\n';
}

void Harl::complain( std::string level )
{
	const std::string commentLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (*functions[4])()

	for (int i = 0; i < 4; i++)
	{
		if (commentLevels[i] == level)
		{

		}
	}
}
