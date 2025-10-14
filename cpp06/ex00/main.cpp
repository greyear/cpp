/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:00:04 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/14 16:00:06 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
		ScalarConverter::convert(argv[1]);
    else
    {
       std::cout << "Usage: ./convert arg" << std::endl;
       return (1);
    }
    return (0);
}
