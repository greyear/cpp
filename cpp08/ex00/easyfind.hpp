/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:21:59 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/28 13:22:01 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& cont, int value)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), value);
	if (it == cont.end())
		throw std::runtime_error("Element is not found in this container");
	return it;
}

template<typename T>
typename T::const_iterator easyfind(const T& cont, int value)
{
	typename T::const_iterator it = std::find(cont.begin(), cont.end(), value);
	if (it == cont.end())
		throw std::runtime_error("Element is not found in this container");
	return it;
}
