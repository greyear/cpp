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
	_name(name), _inventory{nullptr}, _left{nullptr}, _leftIndex(0) //all nulls?? if not make a loop
{
	//std::cout << "Character default constructor called" << std::endl;
	std::cout << "0: " << _inventory[0] << std::endl;
	std::cout << "1: " << _inventory[1] << std::endl;
	std::cout << "2: " << _inventory[2] << std::endl;
	std::cout << "3: " << _inventory[3] << std::endl;
}

Character::Character(const Character& other): _name(other._name), _left{nullptr}, _leftIndex(other._leftIndex) //check also for nulls
{
	//std::cout << "Character copy constructor called" << std::endl;
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
	//std::cout << "Character copy assignment operator called" << std::endl;
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
	//std::cout << "Character destructor called" << std::endl;
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
		std::cout << "Materia is empty and can't be added to the inventory of " << this->getName() << std::endl;
		return ;
	}
	for (int i = 0; i < INVENTORY_CAPACITY; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			std::cout << this->getName() << ": materia " << m->getType() << " is equipped, slot number " << i << std::endl;
			return ;
		}
	}
	std::cout << this->getName() << "'s inventory's full" << std::endl;
	delete m; //without this I have leaks
	m = nullptr;
}

void Character::leaveOnTheFloor(AMateria* m)
{
	if (m == nullptr) //overkill?
	{
		std::cout << "Materia is empty and can't be dropped by " << this->getName() << std::endl;
		return ;
	}
	if (_leftIndex < LEFT_CAPACITY)
	{
		_left[_leftIndex] = m;
		_leftIndex++;
	}
	else
	{
		delete _left[0];
		_left[0] = nullptr;
		for (int i = 1; i < LEFT_CAPACITY; i++)
			_left[i - 1] = _left[i];
		_left[LEFT_CAPACITY - 1] = m;
	}
	std::cout << "Materia " << m->getType() << " is dropped on the floor by " << this->getName() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_CAPACITY)
	{
		std::cout << "Wrong index of materia to unequip " << this->getName() << std::endl;
		return;
	}
	if (_inventory[idx] == nullptr)
	{
		std::cout << "Materia with this index doesn't exist, " << this->getName() << " can't be unequipped" << std::endl;
		return;
	}	
	std::cout << this->getName() << "'s inventory " << idx << " slot (" <<  _inventory[idx]->getType() << ") is unequipped" << std::endl;
	leaveOnTheFloor(_inventory[idx]);
	_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_CAPACITY)
	{
		std::cout << "Wrong index of materia to use by " << this->getName() << std::endl;
		return;
	}
	if (_inventory[idx] == nullptr)
	{
		std::cout << this->getName() << ": materia with this index doesn't exist" << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
