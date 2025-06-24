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
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	{
	DiamondTrap louise("Louise");
	DiamondTrap chloe("Chloe");

	std::cout << std::endl;

	louise.attack("Chloe");
	chloe.takeDamage(30);
	chloe.beRepaired(100);
	chloe.guardGate();
	chloe.highFivesGuys();
	chloe.whoAmI();

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	DiamondTrap marine("Marine");
	DiamondTrap antoine("Antoine");

	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		marine.attack("Antoine");
		antoine.takeDamage(30);
	}
	marine.attack("Antoine");
	antoine.takeDamage(30);
	antoine.beRepaired(5);

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	DiamondTrap clement("Clement");
	DiamondTrap paul("Paul");

	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		clement.attack("Paul");
		paul.takeDamage(30);
	}
	paul.attack("Clement");

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	DiamondTrap marion("Marion");
	DiamondTrap justine("Justine");

	std::cout << std::endl;

	marion.attack("Justine");
	justine.takeDamage(30);
	justine.beRepaired(4294967295);

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	DiamondTrap gabriel("Gabriel");
	DiamondTrap copy(gabriel);
	DiamondTrap assignment("Assignment");
	assignment = gabriel;
	DiamondTrap daniel("Daniel");

	std::cout << std::endl;

	gabriel.attack("Daniel");
	copy.attack("Daniel");
	assignment.attack("Daniel");

	std::cout << std::endl;
	}

	return (0);
}