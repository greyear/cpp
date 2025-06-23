/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:58:24 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/18 20:58:25 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	{
	ScavTrap louise("Louise");
	ScavTrap chloe("Chloe");

	std::cout << std::endl;

	louise.attack("Chloe");
	chloe.takeDamage(20);
	chloe.beRepaired(100);
	chloe.guardGate();

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	ScavTrap marine("Marine");
	ScavTrap antoine("Antoine");

	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		marine.attack("Antoine");
		antoine.takeDamage(20);
	}
	marine.attack("Antoine");
	antoine.takeDamage(20);
	antoine.beRepaired(5);

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	ScavTrap clement("Clement");
	ScavTrap paul("Paul");

	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		clement.attack("Paul");
		paul.takeDamage(20);
	}
	paul.attack("Clement");

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	ScavTrap marion("Marion");
	ScavTrap justine("Justine");

	std::cout << std::endl;

	marion.attack("Justine");
	justine.takeDamage(20);
	justine.beRepaired(4294967295);

	std::cout << std::endl;
	}
	return (0);
}