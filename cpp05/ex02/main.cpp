/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:21:23 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 15:21:25 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void shrubberySuccess(void)
{
    std::cout << "\n1) shrubbery form success path test" << std::endl;

    Bureaucrat shawn("Shawn", 130);
    std::cout << shawn << std::endl;
    ShrubberyCreationForm sh("some_trees");
    std::cout << sh << std::endl;
    shawn.signForm(sh);
    shawn.executeForm(sh);
}

void shrubberyNotSigned(void)
{
    std::cout << "\n2) shrubbery form wasn't signed before executing" << std::endl;

    Bureaucrat roman("Roman", 130);
    std::cout << roman << std::endl;
    ShrubberyCreationForm ns("not_signed_trees");
    std::cout << ns << std::endl;
    roman.executeForm(ns);
}

void shrubberyFileWithNoPerm(void)
{
    std::cout << "\n3) shrubbery form file with bad permissions" << std::endl;

    Bureaucrat alex("Alex", 130);
    std::cout << alex << std::endl;
    ShrubberyCreationForm rs("restricted_trees"); //change permissions!
    std::cout << rs << std::endl;
    alex.signForm(rs);
    alex.executeForm(rs);
}

void robotomySuccess(void)
{
    std::cout << "\n4) robotomy form success random test" << std::endl;

    Bureaucrat mike("Mike", 40);
    std::cout << mike << std::endl;
    RobotomyRequestForm rd("pure random form");
    std::cout << rd << std::endl;
    mike.signForm(rd);
    mike.executeForm(rd);
}

void presidentialSuccess(void)
{
    std::cout << "\n5) presidential pardon form success test" << std::endl;

    Bureaucrat jury("Jury", 3);
    std::cout << jury << std::endl;
    PresidentialPardonForm pr("cat waiting for a pardon");
    std::cout << pr << std::endl;
    jury.signForm(pr);
    jury.executeForm(pr);
}

int main(void)
{
    shrubberySuccess();
    shrubberyNotSigned();
    shrubberyFileWithNoPerm();
    robotomySuccess();
    presidentialSuccess();

    return (0);
}
