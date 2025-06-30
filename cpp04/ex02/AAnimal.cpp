/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:32:53 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/25 17:32:55 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "Some default animal sound" << std::endl;
}

const std::string& AAnimal::getType() const
{
	return (this->type);
}