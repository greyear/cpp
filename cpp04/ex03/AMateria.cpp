/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:04:28 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/30 20:04:29 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type)
{
	//std::cout << "Materia default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other): _type(other.getType())
{
	//std::cout << "Materia copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	//std::cout << "Materia copy assignment operator called" << std::endl;
	if (this != &other) {}
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << "Materia destructor called" << std::endl;
}

std::string const& AMateria::getType() const
{
	return (this->_type);
}
