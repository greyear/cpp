/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:02:14 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/08 21:02:16 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	zombie = "HI THIS IS BRAIN";
	std::string* stringPTR = &zombie;
	std::string &stringREF = zombie;

	std::cout << "The memory address of the string variable:" << &zombie << std::endl;
	std::cout << "The memory address held by stringPTR:" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:" << &stringREF << std::endl;

	std::cout << "The value of the string variable:" << zombie << std::endl;
	std::cout << "The value pointed to by stringPTR:" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:" << stringREF << std::endl;
	return (0);
}
