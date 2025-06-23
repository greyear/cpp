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
	std::cout << "ClapTrap constructor with parameters called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other):
	_name(other._name), _hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
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
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "Oh, ClapTrap " << _name << " is unfortunately dead (has no hit points) and can't attack!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " doesn't have energy points to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "Oh, ClapTrap " << _name << " is unfortunately dead (has no hit points) and can't take damage!" << std::endl;
		return ;
	}
	if (_hitPoints < amount)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " was attacked and lost all his hit points, now has 0!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " was attacked and lost " << amount
		<< " hit points, now " << _hitPoints << " hit points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "Oh, ClapTrap " << _name << " is unfortunately dead (has no hit points) and can't be repaired!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " doesn't have energy points to repair" << std::endl;
		return ;
	}
	if (amount > UINT_MAX - _hitPoints)
	{
		_hitPoints = UINT_MAX;
		std::cout << "Overflow when repairing Claptrap " << _name << ", now has max hit points: "
			<< _hitPoints << std::endl;
		_energyPoints--;
		return ;
	}
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " was repaired and gained " << amount
		<< " hit points, now has " << _hitPoints << " hit points" << std::endl;
	_energyPoints--;
}
