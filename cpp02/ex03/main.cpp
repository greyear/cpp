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
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.0f, 5.0f);

	Point p1(2.0f, 2.0f);
	std::cout << "Test case 1: Point inside the triangle\n";
	std::cout << "Expected: 1, ";
	std::cout << "Returns: " << bsp(a, b, c, p1) << std::endl << std::endl;

	Point p2(2.5f, 0.0f);
	std::cout << "Test case 2: Point on side AB\n";
	std::cout << "Expected: 0, ";
	std::cout << "Returns: " << bsp(a, b, c, p2) << std::endl << std::endl;

	Point p3(3.5f, 2.5f);
	std::cout << "Test case 3: Point on side BC\n";
	std::cout << "Expected: 0, ";
	std::cout << "Returns: " << bsp(a, b, c, p3) << std::endl << std::endl;

	Point p4(1.0f, 2.5f);
	std::cout << "Test case 4: Point on side CA\n";
	std::cout << "Expected: 0, ";
	std::cout << "Returns: " << bsp(a, b, c, p4) << std::endl << std::endl;

	Point p5 = a;
	std::cout << "Test case 5: Point at vertex A\n";
	std::cout << "Expected: 0, ";
	std::cout << "Returns: " << bsp(a, b, c, p5) << std::endl << std::endl;

	Point p6 = b;
	std::cout << "Test case 6: Point at vertex B\n";
	std::cout << "Expected: 0, ";
	std::cout << "Returns: " << bsp(a, b, c, p6) << std::endl << std::endl;

	Point p7 = c;
	std::cout << "Test case 7: Point at vertex C\n";
	std::cout << "Expected: 0, ";
	std::cout << "Returns: " << bsp(a, b, c, p7) << std::endl << std::endl;

	Point p8(5.0f, 5.0f);
	std::cout << "Test case 8: Point outside (upper right)\n";
	std::cout << "Expected: 0, ";
	std::cout << "Returns: " << bsp(a, b, c, p8) << std::endl << std::endl;

	Point p9(-1.0f, -1.0f);
	std::cout << "Test case 9: Point outside (bottom left)\n";
	std::cout << "Expected: 0, ";
	std::cout << "Returns: " << bsp(a, b, c, p9) << std::endl << std::endl;

	Point p10(2.0f, -1.0f);
	std::cout << "Test case 10: Point outside (below AB)\n";
	std::cout << "Expected: 0, ";
	std::cout << "Returns: " << bsp(a, b, c, p10) << std::endl << std::endl;

	return (0);
}
