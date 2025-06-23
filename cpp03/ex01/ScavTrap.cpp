/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:57:42 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/19 18:57:44 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap constructor with parameters called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) //copy constructor chaining
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other); //please use the logic of copy assignment operator of parent class
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "Oh, ScavTrap " << _name << " is unfortunately dead (has no hit points) and can't attack!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " doesn't have energy points to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "Oh, ScavTrap " << _name << " is unfortunately dead (has no hit points) and can't take damage!" << std::endl;
		return ;
	}
	if (_hitPoints < amount)
	{
		_hitPoints = 0;
		std::cout << "ScavTrap " << _name << " was attacked and lost all his hit points, now has 0!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ScavTrap " << _name << " was attacked and lost " << amount
		<< " hit points, now " << _hitPoints << " hit points left" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "Oh, ScavTrap " << _name << " is unfortunately dead (has no hit points) and can't be repaired!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " doesn't have energy points to repair" << std::endl;
		return ;
	}
	if (amount > UINT_MAX - _hitPoints)
	{
		_hitPoints = UINT_MAX;
		std::cout << "Overflow when repairing ScavTrap " << _name << ", now has max hit points: "
			<< _hitPoints << std::endl;
		_energyPoints--;
		return ;
	}
	_hitPoints += amount;
	std::cout << "ScavTrap " << _name << " was repaired and gained " << amount
		<< " hit points, now has " << _hitPoints << " hit points" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
