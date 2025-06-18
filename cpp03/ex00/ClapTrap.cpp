/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:58:15 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/18 20:58:17 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other):
	_name(other._name), _hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	//causes its target to lose <attack damage> hit points.
	if (_energyPoints < 0)
		std::cout << "ClapTrap " << _name << " doesn't have enough points to attach!" << std::endl;
	else
	{
		energyPoints--; //add overflow
		std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " <<
			<< <damage> << "points of damage!" << std::endl;
	}
		_
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount; //add overflow and check > 0
	std::cout << "ClapTrap " << _name << " was attacked and lost " << amount
		<< " hit points " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	_hitPoints += amount; //add overflow
	if (_energyPoints > 0)
		_energyPoints--; //add overflow
}

