
#include "MutantStack.hpp"
#include <iostream>

int main()
{
	//creating stack
	MutantStack<int> mstack;

	//adding 2 elements
	mstack.push(5);
	mstack.push(17);

	//printing top element
	std::cout << mstack.top() << std::endl;

	//deleting top element
	mstack.pop();

	//printing size after
	std::cout << mstack.size() << std::endl;

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
	--it;

	//printing all elements
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	//creating real stack
	std::stack<int> s(mstack);
	return 0;
}
