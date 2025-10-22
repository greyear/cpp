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

void dataType(const int& num)
{
	std::cout << "It's a number: " << num << ", ";
}

void dataType(const std::string& str)
{
	std::cout << "It's a string: " << str << ", ";
}

template<typename T>
void printingWithCommas(T& i)
{
	std::cout << i << ", ";
}

int main(void)
{
	std::cout << std::endl;
	std::cout << "Test case 1: int array x2" << std::endl;
	int arrInt[] = {0, 1, -1, 5};
	std::cout << "original array:" << std::endl;
	iter(arrInt, 4, [](int& i){ std::cout << i << " "; });
	iter(arrInt, 4, toDouble);
	std::cout << std::endl;
	std::cout << "doubled array:" << std::endl;
	iter(arrInt, 4, [](int& i){ std::cout << i << " "; });
	std::cout << std::endl << std::endl;

	std::cout << "Test case 2: double array x2" << std::endl;
	double arrDouble[] = {0.3, -5.4, -9.1, 180.0};
	std::cout << "original array:" << std::endl;
	iter(arrDouble, 4, [](double& d){ std::cout << d << " "; });
	iter(arrDouble, 4, [](double& d){ d *= 2; });
	std::cout << std::endl;
	std::cout << "doubled array:" << std::endl;
	iter(arrDouble, 4, [](double& d){ std::cout << d << " "; });
	std::cout << std::endl << std::endl;

	std::cout << "Test case 3: const array printing" << std::endl;
	const int arrConstInt[] = {3, -7, 6};
	std::cout << "array:" << std::endl;
	iter(arrConstInt, 3, [](const int& i){ std::cout << i << " "; });
	std::cout << std::endl << std::endl;

	std::cout << "Test case 4: strings to capital letters" << std::endl;
	std::string arrString[] = {"who", "knows", "what"};
	std::cout << "original array:" << std::endl;
	iter(arrString, 3, [](std::string& i){ std::cout << i << " "; });
	iter(arrString, 3, [](std::string& i){ for (char& c : i) { c = std::toupper(static_cast<char>(c)); }});
	std::cout << std::endl;
	std::cout << "capital letters array:" << std::endl;
	iter(arrString, 3, [](std::string& i){ std::cout << i << " "; });
	std::cout << std::endl << std::endl;

	std::cout << "Test case 5: overloads" << std::endl;
	std::string arrString1[] = {"just", "a", "string"};
	int arrInt1[] = {8, -1};
	iter(arrString1, 3, [](auto& i){ dataType(i); });
	std::cout << std::endl;
	iter(arrInt1, 2, [](auto& i){ dataType(i); });
	std::cout << std::endl << std::endl;

	std::cout << "Test case 6: templates" << std::endl;
	std::string arrString2[] = {"should", "be", "with", "commas"};
	int arrInt2[] = {4};
	iter(arrString2, 4, printingWithCommas<std::string>);
	std::cout << std::endl;
	iter(arrInt2, 1, printingWithCommas<int>);
	std::cout << std::endl << std::endl;

	std::cout << "Test case 7: some empty arrays (nothing should happen)" << std::endl;
	std::string arrEmptyString[] = {};
	iter(arrEmptyString, 0, printingWithCommas<std::string>);
	int arrEmptyInt[] = {};
	iter(arrEmptyInt, 0, printingWithCommas<int>);
	std::cout << std::endl << std::endl;
	std::string* arrNullString = nullptr;
	iter(arrNullString, 0, printingWithCommas<std::string>);

	return 0;
}