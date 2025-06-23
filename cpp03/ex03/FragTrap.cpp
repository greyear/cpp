/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:21:09 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/23 17:21:11 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap constructor with parameters called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "Oh, FragTrap " << _name << " is unfortunately dead (has no hit points) and can't attack!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " doesn't have energy points to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "Oh, FragTrap " << _name << " is unfortunately dead (has no hit points) and can't take damage!" << std::endl;
		return ;
	}
	if (_hitPoints < amount)
	{
		_hitPoints = 0;
		std::cout << "FragTrap " << _name << " was attacked and lost all his hit points, now has 0!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "FragTrap " << _name << " was attacked and lost " << amount
		<< " hit points, now " << _hitPoints << " hit points left" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "Oh, FragTrap " << _name << " is unfortunately dead (has no hit points) and can't be repaired!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " doesn't have energy points to repair" << std::endl;
		return ;
	}
	if (amount > UINT_MAX - _hitPoints)
	{
		_hitPoints = UINT_MAX;
		std::cout << "Overflow when repairing FragTrap " << _name << ", now has max hit points: "
			<< _hitPoints << std::endl;
		_energyPoints--;
		return ;
	}
	_hitPoints += amount;
	std::cout << "FragTrap " << _name << " was repaired and gained " << amount
		<< " hit points, now has " << _hitPoints << " hit points" << std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Please give a high five ✋ to FragTrap " << _name << std::endl;
}
