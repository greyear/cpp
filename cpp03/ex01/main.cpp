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

int	main(void)
{
	{
	ClapTrap louise("Louise");
	ClapTrap chloe("Chloe");

	std::cout << std::endl;

	louise.attack("Chloe");
	chloe.takeDamage(5);
	chloe.beRepaired(3);

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	ClapTrap marine("Marine");
	ClapTrap antoine("Antoine");

	std::cout << std::endl;

	marine.attack("Antoine");
	antoine.takeDamage(10);
	marine.attack("Antoine");
	antoine.takeDamage(1);
	antoine.beRepaired(5);

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	ClapTrap clement("Clement");
	ClapTrap paul("Paul");

	std::cout << std::endl;

	clement.attack("Paul");
	paul.takeDamage(10000000);
	paul.attack("Clement");

	std::cout << std::endl;
	}

	{
	std::cout << std::endl;
	
	ClapTrap marion("Marion");
	ClapTrap justine("Justine");

	std::cout << std::endl;

	marion.attack("Justine");
	justine.takeDamage(6);
	justine.beRepaired(4294967295);

	std::cout << std::endl;
	}
	return (0);
}