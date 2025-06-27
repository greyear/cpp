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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	}

	{
	std::cout << std::endl;
	const WrongAnimal* i = new WrongCat();
	
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the wrong cat sound!

	delete i;
	}

	{
	std::cout << std::endl;
	WrongCat originalWrongCat;
	WrongCat copyCat(originalWrongCat);
	std::cout << copyCat.getType() << " " << std::endl;
	copyCat.makeSound();
	
	Dog originalDog;
	Dog copyDog;
	copyDog = originalDog;
	std::cout << copyDog.getType() << " " << std::endl;
	copyDog.makeSound();
	}

	return 0;
}
