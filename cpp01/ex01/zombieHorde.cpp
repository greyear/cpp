/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:41:02 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/08 18:41:04 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		return (NULL);
	}
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		horde[i].giveName(name);
	}
	return (horde);
}
