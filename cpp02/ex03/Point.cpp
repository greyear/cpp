/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:50:08 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/16 23:50:10 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{

}

Point::Point(const float xVal, const float yVal): _x(Fixed(xVal)), _y(Fixed(yVal))
{

}

Point::Point(const Point& other): _x(other.getX()), _y(other.getY())
{

}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

Point::~Point()
{

}

Fixed Point::getX(void) const
{
	return (_x);
}

Fixed Point::getY(void) const
{
	return (_y);
}

