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
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed::Fixed(const int intVal)
{
	//std::cout << "Int constructor called" << std::endl;
	if (intVal > (INT_MAX >> _fractBits) || intVal < (INT_MIN >> _fractBits))
	{
		std::cout << "Value is out of range: " << intVal << std::endl;
		std::exit(1);
	}
	else
		_value = intVal << _fractBits; //*256
}

Fixed::Fixed(const float floatVal)
{
	//std::cout << "Float constructor called" << std::endl;
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
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_value = other.getRawBits();
	}
	return *this;
};

bool Fixed::operator>(const Fixed& other) const
{
	return (_value > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (_value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_value != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed		res;
	long long	summ;

	summ = static_cast<long long>(_value) + static_cast<long long>(other.getRawBits());
	if (summ > INT_MAX || summ < INT_MIN)
	{
		std::cout << "+ operation overflow with " << _value << " + " << other.getRawBits() << std::endl;
		std::exit(1);
	}
	res.setRawBits(static_cast<int>(summ));
	return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed		res;
	long long	diff;

	diff = static_cast<long long>(_value) - static_cast<long long>(other.getRawBits());
	if (diff > INT_MAX || diff < INT_MIN)
	{
		std::cout << "- operation overflow with " << _value << " - " << other.getRawBits() << std::endl;
		std::exit(1);
	}
	res.setRawBits(static_cast<int>(diff));
	return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed		res;
	long long	prod;

	prod = (static_cast<long long>(_value) * static_cast<long long>(other.getRawBits())) >> _fractBits;
	if (prod > INT_MAX || prod < INT_MIN)
	{
		std::cout << "* operation overflow with " << _value << " * " << other.getRawBits() << std::endl;
		std::exit(1);
	}
	res.setRawBits(static_cast<int>(prod));
	return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed		res;
	long long	quot;

	if (other.getRawBits() == 0)
	{
		std::cout << "Division by 0 error" << std::endl;
		std::exit(1);
	}
	quot = ((static_cast<long long>(_value) << _fractBits)/ static_cast<long long>(other.getRawBits()));
	if (quot > INT_MAX || quot < INT_MIN)
	{
		std::cout << "/ operation overflow with " << _value << " / " << other.getRawBits() << std::endl;
		std::exit(1);
	}
	res.setRawBits(static_cast<int>(quot));
	return (res);
}

Fixed& Fixed::operator++(void)
{
	if (_value == INT_MAX)
	{
		std::cout << "++ operation overflow with " << _value << std::endl;
		std::exit(1);
	}
	++_value;
	return (*this);//(int a = 5; int b = ++a; a becomes 6 AND b=6 too!)
}

Fixed Fixed::operator++(int)
{
	if (_value == INT_MAX)
	{
		std::cout << "++ operation overflow with " << _value << std::endl;
		std::exit(1);
	}
	Fixed	tmp(*this);
	++_value;
	return (tmp); //(int a = 5; int b = a++; b gets 5!!, while a becomes 6)
}

Fixed& Fixed::operator--(void)
{
	if (_value == INT_MIN)
	{
		std::cout << "-- operation overflow with " << _value << std::endl;
		std::exit(1);
	}
	--_value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	if (_value == INT_MIN)
	{
		std::cout << "-- operation overflow with " << _value << std::endl;
		std::exit(1);
	}
	Fixed	tmp(*this);
	--_value;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
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
