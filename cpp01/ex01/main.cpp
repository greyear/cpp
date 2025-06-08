/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:40:28 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/08 18:40:29 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	int amount = 3;
	Zombie*	myHorde = zombieHorde(amount, "Shaun");
	if (myHorde != NULL)
	{
		for (int i = 0; i < amount; ++i)
		{
			myHorde[i].announce();
		}
		delete [] myHorde;
		myHorde = NULL;
	}

	Zombie* notValid = zombieHorde(0, "doesn't matter");
	if (notValid == NULL)
		std::cout << "Super! It didn't allocate anything for non valid N" << std::endl;

	return (0);
}
