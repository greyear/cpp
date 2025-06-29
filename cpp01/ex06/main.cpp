/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:39:28 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/11 13:39:30 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "./harlFilter should have exactly 1 argument" << std::endl;
		return (0);
	}

	Harl	harl;
	harl.switchLevels(argv[1]);

	return (0);
}
