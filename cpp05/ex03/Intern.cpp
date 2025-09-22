/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:24:12 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 15:24:14 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& form, const std::string& b)
{
	static const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	static AForm* (*creators[3])(const std::string&) = {createShrubberyCreationForm, createRobotomyRequestForm, createPresidentialPardonForm};

	for (int i = 0; i < 3; ++i)
	{
		if (form == formNames[i])
		{
			std::cout << "Intern creates " << form << " form" << std::endl;
			return (creators[i](b));
		}
	}
	throw Intern::FormDoesntExistException();
}

const char* Intern::FormDoesntExistException::what() const noexcept
{
	return ("Form doesn’t exist!");
}
