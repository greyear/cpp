/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:06:35 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/27 19:06:37 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < IDEAS_CAPACITY; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < IDEAS_CAPACITY; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& newIdea)
{
	if (index >= 0 && index < IDEAS_CAPACITY)
		this->ideas[index] = newIdea;
	else
		std::cout << "Index's out of range in setIdea" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= IDEAS_CAPACITY)
	{
		std::cout << "Index's out of range in getIdea" << std::endl;
		return ("");
	}
	return (this->ideas[index]);
}

void Brain::printAllIdeas()
{
	for (int i = 0; i < IDEAS_CAPACITY; i++)
		std::cout << this->ideas[i] << std::endl;
}