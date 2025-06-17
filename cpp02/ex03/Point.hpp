/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:49:44 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/16 23:49:45 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point();
		Point(const float xInit, const float yInit);
		Point(const Point& other);

		Point& operator=(const Point& other);

		~Point();

		Fixed getX(void) const;
		Fixed getY(void) const;
};

#endif
