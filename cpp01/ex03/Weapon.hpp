/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:53:59 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/08 21:54:01 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon();
		Weapon(const std::string& type);
		const std::string& getType();
		void setType(const std::string& newType);
};

#endif
