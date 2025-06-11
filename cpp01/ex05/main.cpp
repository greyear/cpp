/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:44:16 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/10 21:44:17 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "./harl doesn't need arguments" << std::endl;
		return (0);
	}
	
	Harl	harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("NON EXISTING");

	return (0);
}
