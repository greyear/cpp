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
	IMateriaSource* src = nullptr;
	ICharacter* me = nullptr;
	ICharacter* bob = nullptr;
	AMateria* tmp1 = nullptr;
	AMateria* tmp2 = nullptr;

	try
	{
		src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		me = new Character("me");

		tmp1 = src->createMateria("ice");
		me->equip(tmp1);
		tmp1 = nullptr;

		tmp2 = src->createMateria("cure");
		me->equip(tmp2);
		tmp2 = nullptr;

		bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;

		if (bob)
			delete bob;
		if (me)
			delete me;
		if (src)
			delete src;
		if (tmp1)
			delete tmp1;
		if (tmp2)
			delete tmp2;
	}
}

void testInventoryCapacity()
{
	ICharacter* rich = nullptr;

	try
	{
		rich = new Character("rich");
		rich->equip(new Ice());
		rich->equip(new Cure());
		rich->equip(new Ice());
		rich->equip(new Cure());
		rich->equip(new Ice());
		delete rich;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;

		if (rich)
			delete rich;
	}
}

void testMateriaSourceCapacity()
{
	IMateriaSource* src = nullptr;

	try
	{
		src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		delete src;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;

		if (src)
			delete src;
	}
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
