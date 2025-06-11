/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:08:42 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/06 20:08:44 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie* heap = newZombie("heapZombie");
	heap->announce();
	delete heap;

	randomChump("stackZombie");
	return (0);
}
