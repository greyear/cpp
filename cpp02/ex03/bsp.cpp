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

//function checks if BOTH c and d are on the same side of the plane from AB
static	bool isSameSide(const Point& a, const Point& b, const Point& c, const Point& d)
{
	Fixed abx = b.getX() - a.getX();
	Fixed aby = b.getY() - a.getY();

	Fixed acx = c.getX() - a.getX();
	Fixed acy = c.getY() - a.getY();

	Fixed adx = d.getX() - a.getX();
	Fixed ady = d.getY() - a.getY();

	Fixed prodAbAc = abx * acy - aby * acx;
	Fixed prodAbAd = abx * ady - aby * adx;

	if (prodAbAc == Fixed(0) || prodAbAd == Fixed(0))
		return (false);
	
	bool res = (prodAbAc > Fixed(0) && prodAbAd > Fixed (0)) ||
			(prodAbAc < Fixed(0) && prodAbAd < Fixed (0));
	return (res);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool res = isSameSide(a, b, c, point) &&
				isSameSide(b, c, a, point) &&
				isSameSide(c, a, b, point);
	return (res);
}