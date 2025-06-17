/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:48:16 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/16 23:48:18 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(0, 0);
	Point b(5, 0);
	Point c(2, 5);

	Point p1(2, 2);
	std::cout << "Test case 1: Point inside the triangle\n";
	std::cout << "Expected: true, ";
	std::cout << "Returns: " << bsp(a, b, c, p1) << std::endl;

	return (0);
}
