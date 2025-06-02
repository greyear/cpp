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
	std::string	input;

	if (argc != 1)
	{
		std::cout << "Program should have no arguments" << std::endl;
		return (0);
	}
	while (1)
	{
		std::cout << "Please enter the command: ADD, SEARCH or EXIT" << std::endl;

		
		std::getline(std::cin, input);
	}

	return (0);
}