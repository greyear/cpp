
#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:


	public:
		Intern() = default;
		Intern(const Intern& other) = delete;
		Intern& operator=(const Intern& other) = delete;
		~Intern() = default;

		static AForm* createShrubberyCreationForm(const std::string& target);
		static AForm* createRobotomyRequestForm(const std::string& target);
		static AForm* createPresidentialPardonForm(const std::string& target);

		AForm* makeForm(const std::string& form, const std::string& b);

		class FormDoesntExistException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};
