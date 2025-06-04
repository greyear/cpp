/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:42:41 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/02 19:31:36 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "utils.hpp"

# define MAX_AMOUNT 8

class PhoneBook
{
	private:
		Contact	_contacts[MAX_AMOUNT];
		int		_index;
		int		_amount;
	public:
		PhoneBook(); //constructor declaration
		void	add(); //method declaration
		void	search() const;

};

#endif
