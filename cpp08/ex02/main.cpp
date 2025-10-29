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
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top element after adding 5 and then 17: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size after popping 1 element: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	std::cout << "*it after ++it: " << *it << std::endl;
	--it;
	std::cout << "*it after --it: " << *it << std::endl;

	std::cout << "elements of mstack: " << std::endl;
	while (it != ite)
	{
		std::cout << "element of mstack: " << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << "\nelements of s (in reverse): " << std::endl;
	while (!s.empty())
	{
		std::cout << "element of stack: " << s.top() << std::endl;
		s.pop();
	}



	std::cout << "\n2) TEST WITH LIST " << std::endl;
	std::list<int> ls;

	ls.push_back(5);
	ls.push_back(17);

	std::cout << "last element after adding 5 and then 17: " << ls.back() << std::endl;

	ls.pop_back();

	std::cout << "size after popping 1 element: " << ls.size() << std::endl;

	ls.push_back(3);
	ls.push_back(5);
	ls.push_back(737);
	ls.push_back(0);

	std::list<int>::iterator itL = ls.begin();
	std::list<int>::iterator iteL = ls.end();

	++itL;
	std::cout << "*itL after ++itL: " << *itL << std::endl;
	--itL;
	std::cout << "*itL after --itL: " << *itL << std::endl;

	std::cout << "elements of list: " << std::endl;
	while (itL != iteL)
	{
		std::cout << "element of list: " << *itL << std::endl;
		++itL;
	}

	return 0;
}
