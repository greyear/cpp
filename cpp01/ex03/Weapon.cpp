/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:54:09 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/08 21:54:10 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(const std::string& type):
	_type(type)
{

}

const std::string& Weapon::getType()
{
	return (_type);
}

void Weapon::setType(const std::string& newType)
{
	_type = newType;
}
