/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:58:41 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/23 21:58:43 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name)
{
	std::cout << "DiamondTrap constructor with parameters called" << std::endl;
	_name = name;
	_hitPoints = FragTrap:: _hitPoints;
	_energyPoints = ScavTrap:: _energyPoints;
	_attackDamage = FragTrap:: _attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	_name = other._name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	_name = other._name;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is: " << this->_name << " and my ClapTrap's name is " << ClapTrap::_name << std::endl;
}
