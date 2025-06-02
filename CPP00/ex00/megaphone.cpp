/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:20:34 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/02 17:07:19 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string word = argv[i];
		for (std::size_t j = 0; j < word.length(); ++j)
		{
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(word[j])));
		}
	}
	std::cout << std::endl;
	return (0);
}
