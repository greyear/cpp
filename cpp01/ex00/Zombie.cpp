/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:09:10 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/06 20:09:13 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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

