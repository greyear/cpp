
#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string	_name;
        bool                _isSigned;
        const int			_gradeToSign;
        const int			_gradeToExecute;
    public:
        Form() = delete;
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        const std::string&	getName() const;
        bool                getIsSigned() const;
		int					getGradeToSign() const;
        int					getGradeToExecute() const;
        void                beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
        class FormIsAlreadySigned : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& out, const Form& f);