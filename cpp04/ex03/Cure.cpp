/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:05:10 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/30 20:05:12 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const //creates deep copy, new object with same content, but absolutely NEW arrays of _materias
{
	std::cout << "Cure clone function called" << std::endl;
	Cure* cure = new Cure(*this);
	return (cure);
}

//AMateria* newIce = ice.clone(); // создает новый Ice
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << name << "’s wounds *" << std::endl; //add name
}
