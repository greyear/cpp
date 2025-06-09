/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:31:11 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/09 17:31:12 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replace.hpp"

bool checkNum(int argc)
{
	if (argc != 4)
	{
		std::cout << "The number of args is wrong. Usage: ./replacer filename s1 s2" << std::endl;
		return (false);
	}
	return (true);
}

bool checkArgs(const std::string& filename, const std::string& s1)
{
	if (filename.empty())
	{
		std::cout << "Filename shouldn't be empty" << std::endl;
		return (false);
	}
	if (s1.empty())
	{
		std::cout << "s1 shouldn't be empty" << std::endl;
		return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	if (!checkNum(argc))
		return (1);
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	if (!checkArgs)
		return (1);
	Replace replace(filename, s1, s2);
	

	return (0);
}
