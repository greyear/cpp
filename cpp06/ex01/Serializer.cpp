/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:37:30 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/15 13:37:32 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t serialized = reinterpret_cast<uintptr_t>(ptr);
	return (serialized);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* deserialized = reinterpret_cast<Data*>(raw);
	return (deserialized);
}

