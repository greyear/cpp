
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false),
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{

}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{

}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

const std::string&  Form::getName() const
{
    return(_name);
}

bool    Form::getIsSigned() const
{
    return(_isSigned);
}

int Form::getGradeToSign() const
{
    return(_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return(_gradeToExecute);
}

void    Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->getGradeToSign())
        throw Form::GradeTooLowException();
    if (_isSigned == true)
        throw Form::FormIsAlreadySigned();
    _isSigned = true;  
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

const char* Form::FormIsAlreadySigned::what() const noexcept
{
    return ("Form is already signed and can't be signed again!");
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << f.getName() << ", is signed: " << f.getIsSigned() <<
    ", grade to sign: " << f.getGradeToSign() <<
    ", grade to execute: " << f.getGradeToExecute() << ".";
	return (out);
}