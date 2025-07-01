/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:06:10 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/30 20:06:11 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

# define MATERIA_CAPACITY 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materias[MATERIA_CAPACITY];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource() override;

		void learnMateria(AMateria* materia) override;
		AMateria* createMateria(std::string const& type) override;
};

#endif