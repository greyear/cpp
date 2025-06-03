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

#include <iostream>
#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook() //constructor realization
{
	
}

void PhoneBook::add() //method realization
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

	_index = (_index + 1) % CONTACTS_AMOUNT;
	if (_amount < CONTACTS_AMOUNT)
		_amount++;
	std::cout << "New contact added" << std::endl;
}
