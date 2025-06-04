/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:42:09 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/02 19:33:45 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		void	printLengthTen(const std::string& field) const;
	public:
		void	fillIn(const std::string& firstName,
				const std::string& lastName,
				const std::string& nickname,
				const std::string& phoneNumber,
				const std::string& darkestSecret);
		void	printSavedContact(int i) const;
		void	printFoundContact() const;
};

#endif
