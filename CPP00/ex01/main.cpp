/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:42:21 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/02 19:07:10 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char *argv[])
{
	(void)argv;

	PhoneBook	phoneBook; //object creation, constructor used?
	std::string	input;

	if (argc != 1)
	{
		std::cout << RED << "Program should have no arguments" << DEF << std::endl;
		return (0);
	}
	while (1)
	{
		std::cout << "\nPlease enter the command (ADD, SEARCH or EXIT): " << std::endl;

		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << RED << "EOF reached. Exiting program" << DEF << std::endl;
				return (0);
			}
			std::cout << RED << "Input error" << DEF << std::endl;
			return (0);
		}
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
		else if (input == "EXIT")
		{
			std::cout << GREEN << "Bye-bye!" << DEF << std::endl;
			break ;
		}
		else
			std::cout << RED << "Unknown command, please try again!" << DEF << std::endl;
	}
	return (0);
}
