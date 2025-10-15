/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:38:17 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/15 15:38:19 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

Base* generate(void)
{
	int value = std::rand() % 3;
	switch (value)
	{
	case 0:
	{
		return (new A());
	}
	case 1:
	{
		return (new B());
	}
	case 2:
	{
		return (new C());
	}
	default:
	{
		return (nullptr);
	}
	}
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "identified type of the object (by pointer) is A" << std::endl;
		return ;
	}
	B* b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "identified type of the object (by pointer) is B" << std::endl;
		return ;
	}
	C* c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "identified type of the object (by pointer) is C" << std::endl;
		return ;
	}
	std::cout << "identified type of the object (by pointer) is unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "identified type of the object (by reference) is A" << std::endl;
		(void)a;
		return ;
	}
	catch(const std::bad_cast& e) {}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "identified type of the object (by reference) is B" << std::endl;
		(void)b;
		return ;
	}
	catch(const std::bad_cast& e) {}
	
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "identified type of the object (by reference) is C" << std::endl;
		(void)c;
		return ;
	}
	catch(const std::bad_cast& e) {}
	std::cout << "identified type of the object (by reference) is unknown" << std::endl;
}

int	main(void)
{
	std::srand(std::time(nullptr));
	try
	{
		for (int i = 0; i < 5; ++i)
		{
			Base* unknownTypeObject = generate();
			identify(unknownTypeObject);
			identify(*unknownTypeObject);

			delete unknownTypeObject;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception is: " << e.what() << '\n';
		return (1);
	}
	return (0);
}
