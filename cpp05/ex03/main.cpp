/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:24:41 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 15:24:43 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void shrubberySuccess(void)
{
    std::cout << "\n1) shrubbery form success path test" << std::endl;

    try
	{
		Intern denis;
		Bureaucrat pasha("Pasha", 100);
		AForm* form;
		form = denis.makeForm("shrubbery creation", "trees");
		std::cout << *form << std::endl;
		std::cout << pasha << std::endl;
		pasha.signForm(*form);
		pasha.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void robotomySuccess(void)
{
    std::cout << "\n2) robotomy form success path test" << std::endl;

    try
	{
		Intern kirill;
		Bureaucrat alla("Alla", 40);
		AForm* form;
		form = kirill.makeForm("robotomy request", "R2D2");
		std::cout << *form << std::endl;
		std::cout << alla << std::endl;
		alla.signForm(*form);
		alla.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void presidentialSuccess(void)
{
    std::cout << "\n3) presidential pardon form success path test" << std::endl;

    try
	{
		Intern pete;
		Bureaucrat eugene("Eugene", 4);
		AForm* form;
		form = pete.makeForm("presidential pardon", "Oleg");
		std::cout << *form << std::endl;
		std::cout << eugene << std::endl;
		eugene.signForm(*form);
		eugene.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void nonExistingForm(void)
{
    std::cout << "\n4) test with a form that doesn't exist" << std::endl;

    try
	{
		Intern ron;
		Bureaucrat leon("Leon", 4);
		AForm* form;
		form = ron.makeForm("mistake form", "Ivan");
		std::cout << *form << std::endl;
		std::cout << leon << std::endl;
		leon.signForm(*form);
		leon.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void notSigned(void)
{
    std::cout << "\n5) a try to execute the form that wasn't signed" << std::endl;

    try
	{
		Intern gary;
		Bureaucrat bob("Bob", 4);
		AForm* form;
		form = gary.makeForm("presidential pardon", "Alex");
		std::cout << *form << std::endl;
		std::cout << bob << std::endl;
		bob.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void lowGrade(void)
{
    std::cout << "\n6) bureaucrat's grade's at first not enough to execute" << std::endl;

    try
	{
		Intern ben;
		Bureaucrat dan("Dan", 60);
		AForm* form;
		form = ben.makeForm("robotomy request", "Human");
		std::cout << *form << std::endl;
		std::cout << dan << std::endl;
		dan.signForm(*form);
		dan.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
    shrubberySuccess();
	robotomySuccess();
	presidentialSuccess();
	nonExistingForm();
	notSigned();
	lowGrade();

    return (0);
}
