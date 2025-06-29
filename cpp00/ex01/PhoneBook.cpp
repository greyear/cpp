/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:42:33 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/02 17:42:35 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //maybe I need to include this here as all the headers should be able to be used separately!
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _index(0), _amount(0)
{

}

void PhoneBook::add()
{
	std::string	firstName = getValidatedInput("Enter First name: ");
	if (firstName.empty()) return ;
	std::string	lastName = getValidatedInput("Enter Last name: ");
	if (lastName.empty()) return ;
	std::string	nickname = getValidatedInput("Enter Nickname: ");
	if (nickname.empty()) return ;
	std::string	phoneNumber = getValidatedInput("Enter Phone number: ");
	if (phoneNumber.empty()) return ;
	std::string	darkestSecret = getValidatedInput("Enter Darkest secret: ");
	if (darkestSecret.empty()) return ;

	_contacts[_index].fillIn(firstName, lastName, nickname, phoneNumber, darkestSecret);

	_index = (_index + 1) % MAX_AMOUNT;
	if (_amount < MAX_AMOUNT)
		++_amount;
	std::cout << GREEN << "New contact added" << DEF << std::endl;
}

void	PhoneBook::search() const
{
	if (_amount == 0)
	{
		std::cout << "No contacts in the phonebook" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" <<  "|" 
			<< std::setw(10) << "First name" <<  "|"
			<< std::setw(10) << "Last name" <<  "|"
			<< std::setw(10) << "Nickname" <<  "|"
			<< std::endl;
	for (int i = 0; i < _amount; ++i)
		_contacts[i].printSavedContact(i);
	int index = getValidatedIndex(_amount);
	_contacts[index].printFoundContact();
}
