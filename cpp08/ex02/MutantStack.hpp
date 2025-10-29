/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:09:19 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/29 13:09:20 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <stack>

template <typename T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:

		using std::stack<T, Container>::stack;
		//Container is type of the container used (by default deque)
		//typename Container::iterator is TYPE of iterator for that container type
		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;
		using reverse_iterator = typename Container::reverse_iterator;
		using const_reverse_iterator = typename Container::const_reverse_iterator;

		MutantStack() = default;
		MutantStack(const MutantStack& other) = default;
		MutantStack& operator=(const MutantStack& other) = default;
		~MutantStack() = default;

		iterator begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}

		const_iterator begin() const
		{
			return (this->c.begin());
		}

		const_iterator end() const
		{
			return (this->c.end());
		}

		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}

		reverse_iterator rend()
		{
			return (this->c.rend());
		}

		const_reverse_iterator rbegin() const
		{
			return (this->c.rbegin());
		}

		const_reverse_iterator rend() const
		{
			return (this->c.rend());
		} 
};
