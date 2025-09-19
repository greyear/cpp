
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : _name(name), _isSigned(false),
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
    _target(target)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

const std::string& AForm::getName() const
{
    return(_name);
}

bool AForm::getIsSigned() const
{
    return(_isSigned);
}

int AForm::getGradeToSign() const
{
    return(_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return(_gradeToExecute);
}

const std::string& AForm::getTarget() const
{
    return(_target);
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    if (_isSigned == true)
        throw AForm::FormIsAlreadySigned();
    _isSigned = true;  
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!_isSigned)
        throw AForm::FormNeedsToBeSigned();
    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
    specificExecution();
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

const char* AForm::FormIsAlreadySigned::what() const noexcept
{
    return ("Form is already signed and can't be signed again!");
}

const char* AForm::FormNeedsToBeSigned::what() const noexcept
{
    return ("Form needs to be signed first to be executed after!");
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << f.getName() << ", is signed: " << f.getIsSigned() <<
    ", grade to sign: " << f.getGradeToSign() <<
    ", grade to execute: " << f.getGradeToExecute() << ".";
	return (out);
}