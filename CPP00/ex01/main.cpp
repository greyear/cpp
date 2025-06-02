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

#include <iostream>
#include "PhoneBook.hpp"

int	main(int argc, char *argv[])
{
	PhoneBook	phoneBook;
	std::string	input;

	if (argc != 1)
	{
		std::cout << "Program should have no arguments" << std::endl;
		return (0);
	}
	while (1)
	{
		std::cout << "Please enter the command: ADD, SEARCH or EXIT" << std::endl;

		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << "EOF reached" << std::endl;
				return (0);
			}
			std::cout << "Input error" << std::endl;
			return (0);
		}
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
		else if (input == "EXIT")

		else
			
	}

	return (0);
}