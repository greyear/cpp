/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:43:14 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/20 15:43:16 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <concepts>
#include <cstddef>

//requires std::invocable<Func, T&> значит "Можно ли вызвать Func с аргументом типа T&?"

template<typename T, typename Func>
requires std::invocable<Func, T&>
void iter(T* arr, std::size_t length, Func function)
{
	if (!arr)
		return ;
	for (std::size_t i = 0; i < length; ++i)
		function(arr[i]);
}

template<typename T, typename Func>
requires std::invocable<Func, const T&>
void iter(const T* arr, std::size_t length, Func function)
{
	if (!arr)
		return ;
	for (std::size_t i = 0; i < length; ++i)
		function(arr[i]);
}
