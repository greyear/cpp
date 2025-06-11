/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:53:39 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/08 21:53:41 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name):
	_name(name), _weapon(NULL)
{

}

HumanB::~HumanB()
{

}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " doesn't have a weapon yet" << std::endl;
}