
#include <iostream>
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
		Bureaucrat pavel("Pasha", 2);
		Intern denis();
		AForm* form = denis.makeForm("shrubbery creation", pavel);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}


int main(void)
{
    shrubberySuccess();

    return (0);
}