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

int	main(void)
{
	{
	FragTrap louise("Louise");
	FragTrap chloe("Chloe");

	std::cout << std::endl;

	louise.attack("Chloe");
	chloe.takeDamage(30);
	chloe.beRepaired(100);
	chloe.highFivesGuys();

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	FragTrap marine("Marine");
	FragTrap antoine("Antoine");

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
	
	FragTrap clement("Clement");
	FragTrap paul("Paul");

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
	
	FragTrap marion("Marion");
	FragTrap justine("Justine");

	std::cout << std::endl;

	marion.attack("Justine");
	justine.takeDamage(30);
	justine.beRepaired(4294967295);

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	FragTrap gabriel("Gabriel");
	FragTrap copy(gabriel);
	FragTrap assignment("Assignment");
	assignment = gabriel;
	FragTrap daniel("Daniel");

	std::cout << std::endl;

	gabriel.attack("Daniel");
	copy.attack("Daniel");
	assignment.attack("Daniel");

	std::cout << std::endl;
	}

	return (0);
}