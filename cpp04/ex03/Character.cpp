/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:04:50 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/30 20:04:52 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const& name):
	_name(name), _inventory{nullptr}, _left{nullptr} //all nulls?? if not make a loop
{
	std::cout << "Character default constructor called" << std::endl;
	std::cout << "0: " << _inventory[0] << std::endl;
	std::cout << "1: " << _inventory[1] << std::endl;
	std::cout << "2: " << _inventory[2] << std::endl;
	std::cout << "3: " << _inventory[3] << std::endl;
}

Character::Character(const Character& other): _name(other._name), _left{nullptr} //check also for nulls
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < INVENTORY_CAPACITY; i++)
	{
		if (other._inventory[i] == nullptr)
			this->_inventory[i] = nullptr;
		else
			this->_inventory[i] = other._inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < INVENTORY_CAPACITY; i++)
		{
			if (_inventory[i] != nullptr)
			{
				delete _inventory[i];
				_inventory[i] = nullptr;
			}
			if (other._inventory[i] == nullptr)
				this->_inventory[i] = nullptr;
			else
				this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < INVENTORY_CAPACITY; i++)
	{
		if (_inventory[i] != nullptr)
		{
			delete _inventory[i];
			_inventory[i] = nullptr;
		}
	}
	for (int i = 0; i < LEFT_CAPACITY; i++)
	{
		if (_left[i] != nullptr)
		{
			delete _left[i];
			_left[i] = nullptr;
		}
	}
}

std::string const& Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m == nullptr)
	{
		std::cout << "Materia is empty and can't be added to the inventory" << std::endl;
		return ;
	}
	for (int i = 0; i < INVENTORY_CAPACITY; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			std::cout << "Materia " << m->getType() << " is equipped" << std::endl;
			return ;
		}
	}
	std::cout << "Character's inventory's full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_CAPACITY)
	{
		std::cout << "Wrong index of materia to unequip" << std::endl;
		return;
	}
	if (_inventory[idx] == nullptr)
	{
		std::cout << "Materia with this index doesn't exist, can't be unequipped" << std::endl;
		return;
	}
	//unequipped
	_inventory[idx] = nullptr;
	std::cout << "Inventory " << idx << " is unequipped" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_CAPACITY)
	{
		std::cout << "Wrong index of materia" << std::endl;
		return;
	}
	if (_inventory[idx] == nullptr)
	{
		std::cout << "Materia with this index doesn't exist" << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
