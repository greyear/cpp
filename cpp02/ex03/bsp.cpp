/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:50:38 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/16 23:50:40 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//checks if BOTH c and d are on the same side of the plane from AB
static	bool isSameSide(const Point& a, const Point& b, const Point& c, const Point& d)
{
	//vector ab
	Fixed abx = b.getX() - a.getX();
	Fixed aby = b.getY() - a.getY();

	//ac
	Fixed acx = c.getX() - a.getX();
	Fixed acy = c.getY() - a.getY();

	//ad
	Fixed adx = d.getX() - a.getX();
	Fixed ady = d.getY() - a.getY();

	//product of ab*ac and ab*ad
	Fixed prodAbAc = abx * acy - aby * acx;
	Fixed prodAbAd = abx * ady - aby * adx;

	if (prodAbAc == Fixed(0) || prodAbAd == Fixed(0)) // c or d are ON the line ab
		return (false);
	
	bool res = (prodAbAc > Fixed(0) && prodAbAd > Fixed (0)) ||
			(prodAbAc < Fixed(0) && prodAbAd < Fixed (0)); //check if c and d are on the same side
	return (res);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool res = isSameSide(a, b, c, point) &&
				isSameSide(b, c, a, point) &&
				isSameSide(c, a, b, point);
	return (res);
}