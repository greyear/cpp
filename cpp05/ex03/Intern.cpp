
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
	static AForm* (*creators[3])(const std::string&);

	for (int i; i < 3; ++i)
	{
		if (form == formNames[i])
			return (creators[i](b));
	}
	throw Intern::FormDoesntExistException();
}

const char* Intern::FormDoesntExistException::what() const noexcept
{
	return ("Form doesn’t exist!");
}
