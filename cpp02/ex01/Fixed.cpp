/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:15:51 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/11 20:15:52 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed::Fixed(const int intVal)
{
	std::cout << "Int constructor called" << std::endl;
	if (intVal > (INT_MAX >> _fractBits) || intVal < (INT_MIN >> _fractBits))
	{
		std::cout << "Value is out of range: " << intVal << std::endl;
		std::exit(1);
	}
	else
		_value = intVal << _fractBits;
}

Fixed::Fixed(const float floatVal)
{
	std::cout << "Float constructor called" << std::endl;
	if (floatVal > (INT_MAX / (1 << _fractBits)) || floatVal < (INT_MIN / (1 << _fractBits)))
	{
		std::cout << "Value is out of range: " << floatVal << std::endl;
		std::exit(1);
	}
	else
		_value = static_cast<int>(roundf(floatVal * (1 << _fractBits)));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_value = other.getRawBits();
	}
	return *this;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (_value);
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(_value) / (1 << _fractBits));
}

int Fixed::toInt( void ) const
{
	return (_value >> _fractBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
