/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:53:27 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/08 21:53:29 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*	_weapon;
	public:
		HumanB(const std::string& name);
		~HumanB();
		void attack(void);
		void setWeapon(Weapon& weapon);
};

#endif
