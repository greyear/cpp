/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:40:48 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/08 18:40:50 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie( std::string givenName ):
	_name(givenName)
{

}

Zombie::~Zombie( void )
{
	std::cout << _name << " is destroyed :(" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}


void Zombie::giveName( std::string name )
{
	_name = name;
}
