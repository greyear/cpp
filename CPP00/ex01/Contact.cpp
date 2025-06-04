/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:41:57 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/02 19:08:08 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::fillIn(const std::string& firstName, 
		const std::string& lastName, const std::string& nickname,
		const std::string& phoneNumber, const std::string& darkestSecret)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

void	Contact::printSavedContact(int i) const
{
	std::cout << std::setw(10) << i << "|";
	printLengthTen(_firstName);
	printLengthTen(_lastName);
	printLengthTen(_nickname);
	std::cout << std::endl;
}

void	Contact::printLengthTen(const std::string& field) const
{
	if (field.length() <= 10)
		std::cout << std::setw(10) << field << "|";
	else
		std::cout << std::setw(10) << field.substr(0, 9) + "." << "|";
}

void	Contact::printFoundContact() const
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
