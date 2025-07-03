/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:05:50 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/30 20:05:52 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void testMandatory()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp; //?
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void testInventoryCapacity()
{
	ICharacter* rich = new Character("rich");
	rich->equip(new Ice());
	rich->equip(new Cure());
	rich->equip(new Ice());
	rich->equip(new Cure());
	rich->equip(new Ice()); //5th!!!!!!!
	delete rich;
}

void testMateriaSourceCapacity()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); //5th
	delete src;
}

void testDeepCopy()
{
	Character a("michael");
	a.equip(new Ice());
	a.equip(new Cure());

	Character b = a;
	a.unequip(0);
	a.use(0, b);
	b.use(0, a);

}

void testWrongMateria()
{
	MateriaSource source;
	source.learnMateria(new Ice());
	AMateria* unknown = source.createMateria("fire");
	if (!unknown)
		std::cout << "Unknown materia type wasn't created" << std::endl;
}

void testWrongUsing()
{
	Character paul("paul");
	Character jack("jack");
	AMateria* m = new Ice();
	paul.equip(m);
	paul.use(-1, jack);
	//paul.use(0, jack);
	paul.unequip(0);
	paul.use(0, jack);
}

void testUnequip()
{
	Character steve("steve");
	AMateria* m = new Ice();
	steve.equip(m);
	steve.unequip(0);
	std::cout << "Materia is not deleted (it's needed to leave it): " << m->getType() << std::endl;
}

int main()
{
	std::cout << "\n------------Test from the subject-------------" << std::endl;
	testMandatory();
	std::cout << "\n------------Capacity tests--------------------" << std::endl;
	testInventoryCapacity();
	testMateriaSourceCapacity();
	std::cout << "\n------------Deep copy tests-------------------" << std::endl;
	testDeepCopy();
	std::cout << "\n------------Wrong input tests-----------------" << std::endl;
	testWrongMateria();
	testWrongUsing();
	std::cout << "\n------------Unequip method test---------------" << std::endl;
	testUnequip();
	return 0;
}
