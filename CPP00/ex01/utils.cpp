/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:19:58 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/03 14:19:59 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string	getValidatedInput(const std::string& prompt)
{
	std::string	input;

	while (1)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << RED << "EOF reached. Exiting program" << DEF << std::endl;
				exit(0);
			}
			std::cout << RED << "Input error" << DEF << std::endl;
			return ("");
		}
		if (!input.empty())
			return (input);
		std::cout << RED << "The field should be not empty :(" << DEF << std::endl;
	}
}

int	getValidatedIndex(int maxCount)
{
	int	index;

	while (1)
	{
		std::cout << "Please enter the index of the contact: ";
		std::cin >> index;
		if (std::cin.eof())
		{
			std::cout << RED << "EOF reached. Exiting program" << DEF <<  std::endl;
			exit(0);
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << RED << "Wrong input: the index should be an int value" << DEF << std::endl;
			continue ;
		}
		if (index < 0 || index >= maxCount)
		{
			std::cin.ignore(INT_MAX, '\n');
			std::cout << RED << "This index doesn't exist" << DEF << std::endl;
			continue ;
		}
		std::cin.ignore(INT_MAX, '\n');
		return (index);
	}
}
