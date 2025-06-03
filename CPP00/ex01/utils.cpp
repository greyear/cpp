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

#include <iostream>
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
				std::cout << "EOF reached" << std::endl;
				return ("");
			}
			std::cout << "Input error" << std::endl;
			return ("");
		}
		if (!input.empty())
			return (input);
		std::cout << "The field should be not empty!" << std::endl;
	}
}

std::string getValidatedInput(const std::string& prompt)
{
	std::string input;
	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cout << "EOF reached" << std::endl;
			exit(0);
		}
		if (!input.empty())
			return input;
		std::cout << "The field should be not empty!" << std::endl;
	}
}