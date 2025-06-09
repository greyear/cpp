/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:53:18 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/08 21:53:20 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon):
	_name(name), _weapon(weapon)
{
	
}

HumanA::~HumanA()
{

}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with " << _weapon.getType() << std::endl;
}