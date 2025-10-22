/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:27:28 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/22 13:27:29 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void)
{
	try
	{
		std::cout << std::endl;
		std::cout << "Test case 1: default constructor" << std::endl;
		Array<int> defaultConstructor;
		std::cout << "size of the array: " << defaultConstructor.size() << std::endl;
		std::cout << std::endl;

		std::cout << "Test case 2: constructor with parameters" << std::endl;
		Array<int> parConstructor(3);
		std::cout << "size of the array: " << parConstructor.size() << std::endl;
		std::cout << "elements (by default): " << std::endl;
		for (unsigned int i = 0; i < parConstructor.size(); ++i)
			std::cout << parConstructor[i] << " ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < parConstructor.size(); ++i)
			parConstructor[i] = i * 10 + 1;
		std::cout << "elements (set values): " << std::endl;
		for (unsigned int i = 0; i < parConstructor.size(); ++i)
			std::cout << parConstructor[i] << " ";
		std::cout << std::endl << std::endl;

		std::cout << "Test case 3: copy constructor" << std::endl;
		Array<int> copyConstructor(parConstructor);
		std::cout << "size of the array: " << copyConstructor.size() << std::endl;
		std::cout << "elements of copy array (created): " << std::endl;
		for (unsigned int i = 0; i < copyConstructor.size(); ++i)
			std::cout << copyConstructor[i] << " ";
		for (unsigned int i = 0; i < parConstructor.size(); ++i)
			parConstructor[i] = i * 10 + 2;
		std::cout << std::endl;
		std::cout << "elements of original array (changed): " << std::endl;
		for (unsigned int i = 0; i < parConstructor.size(); ++i)
			std::cout << parConstructor[i] << " ";
		std::cout << std::endl;
		std::cout << "elements of copy array (unchanged): " << std::endl;
		for (unsigned int i = 0; i < copyConstructor.size(); ++i)
			std::cout << copyConstructor[i] << " ";
		std::cout << std::endl << std::endl;

		std::cout << "Test case 4: copy assignment operator" << std::endl;
		std::cout << "elements of the array to where we're copying (before copying): " << std::endl;
		for (unsigned int i = 0; i < copyConstructor.size(); ++i)
			std::cout << copyConstructor[i] << " ";
		std::cout << std::endl;
		std::cout << "elements of original array (from where we're copying): " << std::endl;
		for (unsigned int i = 0; i < parConstructor.size(); ++i)
			std::cout << parConstructor[i] << " ";
		std::cout << std::endl;
		copyConstructor = parConstructor;
		std::cout << "elements of the array to where we're copying (after copying): " << std::endl;
		for (unsigned int i = 0; i < copyConstructor.size(); ++i)
			std::cout << copyConstructor[i] << " ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < copyConstructor.size(); ++i)
			copyConstructor[i] = i * 10 + 3;
		std::cout << "elements of copied array (changed): " << std::endl;
		for (unsigned int i = 0; i < copyConstructor.size(); ++i)
			std::cout << copyConstructor[i] << " ";
		std::cout << std::endl;
		std::cout << "elements of the original array (unchanged): " << std::endl;
		for (unsigned int i = 0; i < parConstructor.size(); ++i)
			std::cout << parConstructor[i] << " ";
		std::cout << std::endl << std::endl;

		std::cout << "Test case 5: string array" << std::endl;
		Array<std::string> stringConstructor(4);
		stringConstructor[0] = "very";
		stringConstructor[1] = "delicious";
		stringConstructor[2] = "marzipan";
		stringConstructor[3] = "mmmm";
		std::cout << "elements: " << std::endl;
		for (unsigned int i = 0; i < stringConstructor.size(); ++i)
			std::cout << stringConstructor[i] << " ";
		std::cout << std::endl << std::endl;

		std::cout << "Test case 6: double array" << std::endl;
		Array<double> doubleConstructor(4);
		for (unsigned int i = 0; i < doubleConstructor.size(); ++i)
			doubleConstructor[i] = i * 3.1 + 10.1;
		std::cout << "elements: " << std::endl;
		for (unsigned int i = 0; i < doubleConstructor.size(); ++i)
			std::cout << doubleConstructor[i] << " ";
		std::cout << std::endl << std::endl;

		std::cout << "Test case 7: exception" << std::endl;
		Array<int> anotherConstructor(3);
		std::cout << "size of the array: " << anotherConstructor.size() << std::endl;
		anotherConstructor[3] = 5;
		std::cout << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception is caught: " << e.what() << std::endl;
	}

	return (0);
}
