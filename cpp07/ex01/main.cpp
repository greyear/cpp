/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:43:05 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/20 15:43:07 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void toDouble(int& a)
{
	a *= 2;
}

void dataType(int& num)
{
	std::cout << "It's a number - " << num << std::endl;
}

void dataType(std::string& str)
{
	std::cout << "It's a string - " << str << std::endl;
}

template<typename T>
void printingWithCommas(T& i)
{
	std::cout << i << ", ";
}

int main( void )
{
	std::cout << "Test case 1: array x2" << std::endl;
	int arrInt[] = {0, 1, -1, 5};
	std::cout << "original array:" << std::endl;
	iter(arrInt, 4, [](int& i){ std::cout << i << " "; });
	iter(arrInt, 4, toDouble);
	std::cout << std::endl;
	std::cout << "doubled array:" << std::endl;
	iter(arrInt, 4, [](int& i){ std::cout << i << " "; });
	std::cout << std::endl << std::endl;

	std::cout << "Test case 2: const array printing" << std::endl;
	const int arrConstInt[] = {3, -7, 6};
	std::cout << "array:" << std::endl;
	iter(arrConstInt, 3, [](const int& i){ std::cout << i << " "; });
	std::cout << std::endl << std::endl;

	std::cout << "Test case 3: strings" << std::endl;
	

	return 0;
}