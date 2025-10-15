/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:37:15 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/15 13:37:17 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data myData{"Alexander", 3, 4.8};
	Data* originalPtr = &myData;

	uintptr_t serialized = Serializer::serialize(originalPtr);
	Data* deserialized = Serializer::deserialize(serialized);

	if (originalPtr == deserialized)
	{
		std::cout << "It works!\n" << std::endl;
		std::cout << "POINTERS:  " << originalPtr << " vs " << deserialized << std::endl;
		std::cout << "NAMES:     " << myData.name << " vs " << deserialized->name << std::endl;
		std::cout << "IDS:       " << myData.id << " vs " << deserialized->id << std::endl;
		std::cout << "VALUES:    " << myData.value << " vs " << deserialized->value << std::endl;
	}
	else
	{
		std::cout << "It doesn't work" << std::endl;
	}
	return (0);
}