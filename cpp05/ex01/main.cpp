/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:20:13 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 15:20:16 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void successPath(void)
{
    std::cout << "\n1) success path test" << std::endl;
    try
    {
        Bureaucrat shawn("Shawn", 3);
        std::cout << shawn << std::endl;
        Form form("Very important form", 4, 2);
        std::cout << form << std::endl;
        shawn.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void gradesAreTheSame(void)
{
    std::cout << "\n2) bureaucrat's grade is the same with form's grade to sign" << std::endl;
    try
    {
        Bureaucrat konstantin("Konstantin", 3);
        std::cout << konstantin << std::endl;
        Form form("Very important form", 3, 2);
        std::cout << form << std::endl;
        konstantin.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void formWithTwoLowGrades(void)
{
    std::cout << "\n3) creating form with low grade to sign and low grade to execute" << std::endl;
    try
    {
        Form form("Very important form", 151, 152);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void formWithOneLowAndOneHigh(void)
{
    std::cout << "\n4) creating form with high grade to sign and low grade to execute" << std::endl;
    try
    {
        Form form("Very important form", 0, 151);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void tooLowToSign(void)
{
    std::cout << "\n5) bureaucrat with low grade's signing form with higher grade to sign" << std::endl;
    try
    {
        Bureaucrat alex("Alex", 3);
        std::cout << alex << std::endl;
        Form form("Very important form", 2, 4);
        std::cout << form << std::endl;
        alex.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void alreadySigned(void)
{
    std::cout << "\n6) bureaucrat's trying to sign one form twice" << std::endl;
    try
    {
        Bureaucrat shawn("Shawn", 3);
        std::cout << shawn << std::endl;
        Form form("Very important form", 150, 150);
        std::cout << form << std::endl;
        shawn.signForm(form);
        std::cout << form << std::endl;
        shawn.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void signedByTwo(void)
{
    std::cout << "\n7) two bureaucrats're trying to sign one form" << std::endl;
    try
    {
        Bureaucrat shawn("Shawn", 3);
        std::cout << shawn << std::endl;
        Form form("Very important form", 4, 1);
        std::cout << form << std::endl;
        shawn.signForm(form);
        std::cout << form << std::endl;
        Bureaucrat paul("Paul", 3);
        std::cout << paul << std::endl;
        paul.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    successPath();
    gradesAreTheSame();
    formWithTwoLowGrades();
    formWithOneLowAndOneHigh();
    tooLowToSign();
    alreadySigned();
    signedByTwo();

    return (0);
}
