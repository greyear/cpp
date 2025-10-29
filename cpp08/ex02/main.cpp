/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:09:03 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/29 13:09:05 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
	std::cout << "\n1) TEST FROM SUBJECT " << std::endl;
	//creating stack
	MutantStack<int> mstack;

	//adding 2 elements
	mstack.push(5);
	mstack.push(17);

	//printing top element
	std::cout << "top element after adding 5 and then 17: " << mstack.top() << std::endl;

	//deleting top element
	mstack.pop();

	//printing size after
	std::cout << "size after popping 1 element: " << mstack.size() << std::endl;

	//adding 4 more elements
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	//creating iterators
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	//movind iterators
	++it;
	std::cout << "*it after ++it: " << *it << std::endl;
	--it;
	std::cout << "*it after --it: " << *it << std::endl;

	//printing all elements of mstack using our created iterator
	std::cout << "elements of mstack: " << std::endl;
	while (it != ite)
	{
		std::cout << "element of mstack: " << *it << std::endl;
		++it;
	}

	//creating real stack by copying
	std::stack<int> s(mstack);

	//printing all elements of s by taking the top and popping (reverse order!)
	std::cout << "\nelements of s (in reverse): " << std::endl;
	while (!s.empty())
	{
		std::cout << "element of stack: " << s.top() << std::endl;
		s.pop();
	}

	//////////////////////////////////////////////

	//test with list instead of mstack
	std::cout << "\n2) TEST WITH LIST " << std::endl;
	//creating list
	std::list<int> ls;

	//adding 2 elements
	ls.push_back(5);
	ls.push_back(17);

	//printing last element
	std::cout << "last element after adding 5 and then 17: " << ls.back() << std::endl;

	//deleting last element
	ls.pop_back();

	//printing size after
	std::cout << "size after popping 1 element: " << ls.size() << std::endl;

	//adding 4 more elements
	ls.push_back(3);
	ls.push_back(5);
	ls.push_back(737);
	ls.push_back(0);

	//creating iterators
	std::list<int>::iterator itL = ls.begin();
	std::list<int>::iterator iteL = ls.end();

	//movind iterators
	++itL;
	std::cout << "*itL after ++itL: " << *itL << std::endl;
	--itL;
	std::cout << "*itL after --itL: " << *itL << std::endl;

	//printing all elements of list
	std::cout << "elements of list: " << std::endl;
	while (itL != iteL)
	{
		std::cout << "element of list: " << *itL << std::endl;
		++itL;
	}

	return 0;
}
