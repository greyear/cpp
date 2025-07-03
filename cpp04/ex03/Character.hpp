/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:04:59 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/30 20:05:01 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

# define INVENTORY_CAPACITY 4
# define LEFT_CAPACITY 20

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[INVENTORY_CAPACITY];
		AMateria*	_left[LEFT_CAPACITY];
		int			_leftIndex;
		void		leaveOnTheFloor(AMateria* m);

	public:
		Character() = delete;
		Character(std::string const& name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character() override;

		std::string const& getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
};

#endif