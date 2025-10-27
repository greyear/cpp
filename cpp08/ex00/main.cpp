
#include "easyfind.hpp"
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <iostream>

void testVector(void)
{
	try
	{
		std::cout << "Test case 1: vectors" << std::endl;
		std::vector<int> vec = {3, 1, -8, 3};
		std::cout << "Vector elements: " << std::endl;
		std::vector<int>::iterator it;
		for (it = vec.begin(); it != vec.end(); ++it)
			std::cout << *it << " ";
		std::cout << "\nTrying to find element 3: ";
		int* correctPointer = &vec[0];
		std::vector<int>::iterator res = easyfind(vec, 3);
		std::cout << *res << std::endl;
		std::cout << "Address of element expected: " << correctPointer << std::endl;
		std::cout << "Address of element found: " << &(*res) << std::endl;
		
		std::cout << "Trying to find element 10: ";
		std::cout << *easyfind(vec, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testArray(void)
{
	try
	{
		std::cout << "\nTest case 2: arrays" << std::endl;
		std::array<const int, 5> arr = {0, -9, -2, 1, 10000};
		std::cout << "Array elements: " << std::endl;
		std::array<const int, 5>::const_iterator it;
		for (it = arr.begin(); it != arr.end(); ++it)
			std::cout << *it << " ";
		std::cout << "\nTrying to find element -2: ";
		const int* correctPointer = &arr[2];
		std::array<const int, 5>::const_iterator res = easyfind(arr, -2);
		std::cout << *res << std::endl;
		std::cout << "Address of element expected: " << correctPointer << std::endl;
		std::cout << "Address of element found: " << &(*res) << std::endl;
		
		std::cout << "Trying to find element 10: ";
		std::cout << *easyfind(arr, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main(void)
{
	testVector();
	testArray();
	
	return (0);
}
