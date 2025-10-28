
#include "easyfind.hpp"
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <iostream>

void testVector(void)
{
	try
	{
		std::cout << "Test case 1: vector" << std::endl;
		std::vector<int> vec = {3, 1, -8, 3};
		std::cout << "Vector elements: " << std::endl;
		std::vector<int>::iterator it;
		for (it = vec.begin(); it != vec.end(); ++it)
			std::cout << *it << " ";
		std::cout << "\nTrying to find element 3: ";
		int* correctPointer = &vec[0];
		std::vector<int>::iterator res = easyfind(vec, 3);
		std::cout << *res << std::endl;
		if (&(*res) == correctPointer)
   			std::cout << "Correct element found (addresses match)" << std::endl;
		else
    		std::cout << "Wrong element found" << std::endl;

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
		std::cout << "\nTest case 2: array" << std::endl;
		std::array<const int, 5> arr = {0, -9, -2, 1, 10000};
		std::cout << "Array elements: " << std::endl;
		std::array<const int, 5>::iterator it;
		for (it = arr.begin(); it != arr.end(); ++it)
			std::cout << *it << " ";
		std::cout << "\nTrying to find element -2: ";
		const int* correctPointer = &arr[2];
		std::array<const int, 5>::iterator res = easyfind(arr, -2);
		std::cout << *res << std::endl;
		if (&(*res) == correctPointer)
   			std::cout << "Correct element found (addresses match)" << std::endl;
		else
    		std::cout << "Wrong element found" << std::endl;

		std::cout << "Trying to find element 10: ";
		std::cout << *easyfind(arr, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testList(void)
{
	try
	{
		std::cout << "\nTest case 3: list" << std::endl;
		const std::list<int> ls = {6, 18, -200};
		std::cout << "List elements: " << std::endl;
		std::list<int>::const_iterator it;
		for (it = ls.begin(); it != ls.end(); ++it)
			std::cout << *it << " ";
		std::cout << "\nTrying to find element 18: ";
		std::list<int>::const_iterator cit = ls.begin();
		std::advance(cit, 1);
		const int* correctPointer = &(*cit);
		std::list<int>::const_iterator res = easyfind(ls, 18);
		std::cout << *res << std::endl;
		if (&(*res) == correctPointer)
   			std::cout << "Correct element found (addresses match)" << std::endl;
		else
    		std::cout << "Wrong element found" << std::endl;

		std::cout << "Trying to find element 10: ";
		std::cout << *easyfind(ls, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testDeque(void)
{
	try
	{
		std::cout << "\nTest case 4: deque" << std::endl;
		std::deque<int> dq = {42, -10000, 0, 12, 12};
		std::cout << "Deque elements: " << std::endl;
		std::deque<int>::iterator it;
		for (it = dq.begin(); it != dq.end(); ++it)
			std::cout << *it << " ";
		std::cout << "\nTrying to find element 12: ";
		int* correctPointer = &dq[3];
		std::deque<int>::iterator res = easyfind(dq, 12);
		std::cout << *res << std::endl;
		if (&(*res) == correctPointer)
   			std::cout << "Correct element found (addresses match)" << std::endl;
		else
    		std::cout << "Wrong element found" << std::endl;

		std::cout << "Trying to find element 10: ";
		std::cout << *easyfind(dq, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testEmpty(void)
{
	try
	{
		std::cout << "\nTest case 5: empty vector" << std::endl;
		std::vector<int> emp;
		std::cout << "Trying to find element 3: ";
		std::vector<int>::iterator res = easyfind(emp, 3);
		std::cout << *res << std::endl;
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
	testList();
	testDeque();
	testEmpty();
	
	return (0);
}
