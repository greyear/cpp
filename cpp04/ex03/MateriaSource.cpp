/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:06:03 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/30 20:06:05 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _materias{nullptr}
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < MATERIA_CAPACITY; i++)
	{
		if (other._materias[i] == nullptr)
			this->_materias[i] = nullptr;
		else
			this->_materias[i] = other._materias[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < MATERIA_CAPACITY; i++)
		{
			if (_materias[i] != nullptr)
			{
				delete _materias[i];
				_materias[i] = nullptr;
			}
			if (other._materias[i] == nullptr)
				this->_materias[i] = nullptr;
			else
				this->_materias[i] = other._materias[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MATERIA_CAPACITY; i++)
	{
		if (_materias[i] != nullptr)
		{
			delete _materias[i];
			_materias[i] = nullptr;
		}
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == nullptr)
		return ;
	for (int i = 0; i < MATERIA_CAPACITY; i++)
	{
		if (_materias[i] == nullptr)
		{
			_materias[i] = materia; //clone???
			std::cout << "Materia " << materia->getType() << " is learned" << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource already stores 4, this one can't be learned" << std::endl;
	delete materia;
	materia = nullptr;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{

}
