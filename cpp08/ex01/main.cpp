/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:24:17 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/28 13:24:19 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void testCorrect(void)
{
	try
	{
		std::cout << "Test case 1: happy path" << std::endl;
		Span span = Span(4);
		span.addNumber(3);
		span.addNumber(100000);
		span.addNumber(-800);
		span.addNumber(2);
		std::cout << "shortest span is: " << span.shortestSpan() << std::endl;
		std::cout << "longest span is: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testAddExtra(void)
{
	try
	{
		std::cout << "\nTest case 2: adding 2nd element when limit is 1" << std::endl;
		Span span = Span(1);
		span.addNumber(1);
		span.addNumber(2);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testZeroElementsContainer(void)
{
	try
	{
		std::cout << "\nTest case 3: creating container with 0 elements" << std::endl;
		Span span = Span(0);
		std::cout << "It was created successfully" << std::endl;
		span.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testOneElementContainer(void)
{
	try
	{
		std::cout << "\nTest case 4: container with 1 element" << std::endl;
		Span span = Span(1);
		span.addNumber(10);
		std::cout << "shortest span is: " << span.shortestSpan() << std::endl;
		std::cout << "longest span is: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testOneElementContainerAndBiggerLimit(void)
{
	try
	{
		std::cout << "\nTest case 5: container with 1 element but bigger limit" << std::endl;
		Span span = Span(20);
		span.addNumber(10);
		std::cout << "shortest span is: " << span.shortestSpan() << std::endl;
		std::cout << "longest span is: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testNotFilledInFully(void)
{
	try
	{
		std::cout << "\nTest case 6: container with 3 elements and limit 20" << std::endl;
		Span span = Span(20);
		span.addNumber(10);
		span.addNumber(40);
		span.addNumber(20);
		std::cout << "shortest span is: " << span.shortestSpan() << std::endl;
		std::cout << "longest span is: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testAllSameValues(void)
{
	try
	{
		std::cout << "\nTest case 7: all numbers are the same" << std::endl;
		Span span = Span(4);
		span.addNumber(3);
		span.addNumber(3);
		span.addNumber(3);
		span.addNumber(3);
		std::cout << "shortest span is: " << span.shortestSpan() << std::endl;
		std::cout << "longest span is: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void testIntLimits(void)
{
	try
	{
		std::cout << "\nTest case 8: trying int limits" << std::endl;
		Span span = Span(3);
		span.addNumber(2147483647);
		span.addNumber(-2147483648);
		span.addNumber(0);
		std::cout << "shortest span is: " << span.shortestSpan() << std::endl;
		std::cout << "longest span is: " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main(void)
{
	testCorrect();
	testAddExtra();
	testZeroElementsContainer();
	testOneElementContainer();
	testOneElementContainerAndBiggerLimit();
	testNotFilledInFully();
	testAllSameValues();
	testIntLimits();

	return (0);
}
