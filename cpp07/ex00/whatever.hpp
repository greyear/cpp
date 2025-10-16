/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:22:03 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/16 14:22:04 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <concepts>

template <typename T>
void swap(T& x, T& y)
{
	T z = x;
	x = y;
	y = z;
}

template <typename T>
const T& min(const T& x, const T& y)
{
	return (x < y) ? x : y;
}

template <typename T>
const T& max(const T& x, const T& y)
{
	return (x > y) ? x : y;
}
