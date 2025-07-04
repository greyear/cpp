/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:34:01 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/25 17:34:03 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testMandatory()
{
	const AAnimal* dog = nullptr;
	const AAnimal* cat = nullptr;

	try
	{
		std::cout << std::endl;
		dog = new Dog();
		cat = new Cat();
		std::cout << std::endl;
		delete dog;
		delete cat;
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		if (dog)
			delete dog;
		if (cat)
			delete cat;
	}
}

void testArray()
{
	const AAnimal* arr[10] = {nullptr};

	try
	{
		std::cout << std::endl;
		for (int i = 0; i < 5; i++)
			arr[i] = new Dog();
		for (int i = 5; i < 10; i++)
			arr[i] = new Cat();
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			delete arr[i];
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		for (int i = 0; i < 10; i++)
		{
			if (arr[i])
				delete arr[i];
		}
	}
}

void testDeepCopy()
{
	std::cout << std::endl;
	Dog dog;
	dog.setIdea(0, "Let's howl at the moon");
	Dog copyDog(dog);
	std::cout << "Right after copying: " << std::endl;
	std::cout << "Original dog thinks: " << dog.getIdea(0) << std::endl;
	std::cout << "Copy dog thinks: " << copyDog.getIdea(0) << std::endl;

	copyDog.setIdea(0, "I don't wanna howl");
	std::cout << "After changing copy's idea: " << std::endl;
	std::cout << "Copy dog thinks: " << copyDog.getIdea(0) << std::endl;
	std::cout << "Original dog thinks: " << dog.getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	Cat cat;
	cat.setIdea(0, "Where's the bird?");
	Cat copyCat;
	copyCat = cat;
	std::cout << "Right after copying: " << std::endl;
	std::cout << "Original cat thinks: " << cat.getIdea(0) << std::endl;
	std::cout << "Copy cat thinks: " << copyCat.getIdea(0) << std::endl;

	copyCat.setIdea(0, "Oh I've eaten the bird already");
	std::cout << "After changing copy's idea: " << std::endl;
	std::cout << "Copy cat thinks: " << copyCat.getIdea(0) << std::endl;
	std::cout << "Original cat thinks: " << cat.getIdea(0) << std::endl;
	std::cout << std::endl;
}

void testWrongNum()
{
	std::cout << std::endl;
	Dog dog;
	dog.setIdea(100, "Let's howl at the moon");
	dog.getIdea(100);
	std::cout << std::endl;

	Cat cat;
	cat.setIdea(-1, "Where's the bird?");
	cat.getIdea(-1);
	std::cout << std::endl;
}

int main()
{
	std::cout << "\n------------Tests from the subject-------------" << std::endl;
	testMandatory();
	testArray();
	std::cout << "\n------------Deep copy tests--------------------" << std::endl;
	testDeepCopy();
	std::cout << "\n------------Wrong num test---------------------" << std::endl;
	testWrongNum();
	//AAnimal cantBeCreated;
	//const AAnimal* cantbeCreatedToo = new AAnimal();
	return 0;
}
