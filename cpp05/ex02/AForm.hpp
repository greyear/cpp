
#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string	_name;
        bool                _isSigned;
        const int			_gradeToSign;
        const int			_gradeToExecute;
        const std::string	_target;
    public:
        AForm() = delete;
        AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
        virtual ~AForm() = default;
        AForm(const AForm& other) = default;
        AForm& operator=(const AForm& other) = delete;

        const std::string&	getName() const;
        bool                getIsSigned() const;
		int					getGradeToSign() const;
        int					getGradeToExecute() const;
        const std::string&	getTarget() const;
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

std::ostream& operator<<(std::ostream& out, const AForm& f);