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
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float xVal, const float yVal): _x(Fixed(xVal)), _y(Fixed(yVal))
{
	std::cout << "Constructor with values called" << std::endl;
}

Point::Point(const Point& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Point& Point::operator=(const Point& other)
{
	std::cout << "Assignment operator called, but Point fields are const" << std::endl;
	return *this;
}

Point::~Point()
{
	std::cout << "Destructor called" << std::endl;
}
