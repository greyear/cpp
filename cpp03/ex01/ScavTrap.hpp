/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:57:35 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/19 18:57:37 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

/*
Inheritance	What happens to base class members in the child?
	public	public stays public, protected stays protected
	protected	public becomes protected, protected stays protected
	private	public and protected both become private

EVEN child class cannot access private fields of parent class!
protected fields are modifiable from this class and all it's children
public class fields are modifiable from anywhere but it's dangerous to use them
*/

class ScavTrap : public ClapTrap
{
	private:
		
	public:
		ScavTrap() = delete;
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();

		void attack(const std::string& target) override;
		void takeDamage(unsigned int amount) override;
		void beRepaired(unsigned int amount) override;
		void guardGate();
};

#endif
