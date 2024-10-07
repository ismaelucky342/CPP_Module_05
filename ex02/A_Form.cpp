/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Form.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:18:40 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/23 13:28:39 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &ref) : _name(ref._name), _signed(ref._signed), _gradeToSign(ref._gradeToSign), _gradeToExecute(ref._gradeToExecute)
{}

AForm &AForm::operator=(const AForm &ref)
{
	if (this != &ref)
	{
		_signed = ref._signed;
	}
	return (*this);
}

AForm::~AForm()
{}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("Form not signed");
}


std::ostream &operator<<(std::ostream &o, const AForm &ref)
{
	o << "Form " << ref.getName() << " is ";
	if (ref.getSigned())
		o << "signed";
	else
		o << "not signed";
	o << " and requires grade " << (int) ref.getGradeToSign() << " to sign and grade " << (int) ref.getGradeToExecute() << " to execute";
	return (o);
}