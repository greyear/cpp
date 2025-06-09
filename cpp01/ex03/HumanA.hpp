/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:53:09 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/08 21:53:10 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;
		//HumanA must always have a Weapon! So I'll use a ref bc it always exists and can't be nothing
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();
		void attack(void);
};

#endif
