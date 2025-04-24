/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:39:55 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/14 19:45:21 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(): _name("Default"), _gradeToSign(150), _gradeToExecute(150)
{
	this->_isSigned = false;
	return;
}

Form::Form(const std::string name): _name(name), _gradeToSign(150), _gradeToExecute(150)
{
	this->_isSigned = false;
	return;
}

Form::Form(const std::string name, unsigned int grade): _name(name), _gradeToSign(grade), _gradeToExecute(150)
{
	this->_isSigned = false;
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw Form::GradeTooLowException();
		
}

Form::Form(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_isSigned = 0;
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copied): _name(copied._name), _gradeToSign(copied._gradeToSign), _gradeToExecute(copied._gradeToExecute)
{
	this->_isSigned = copied._isSigned;
	return;
}

Form::~Form()
{
	return;
}

/*	GETTERS	*/

std::string	Form::getName(void) const
{
	return this->_name;
}

bool	Form::isSigned(void) const
{
	return this->_isSigned;
}

unsigned int	Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

unsigned int	Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

/*	OPERATORS	*/

Form&	Form::operator=(const Form& base)
{
	if (this != &base)
		this->_isSigned = base._isSigned;
	return *this;
}

std::ostream&	operator<<(std::ostream& o, Form& f)
{
	o << "Form : " << f.getName();
		if (f.isSigned())
			o << " is signed.";
		else
			o << " is not signed.";
		o << " The grade needed to be at: " << f.getGradeToSign() << " to sign.";
	return o;
}

/*	ERROR MESSAGES	*/

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too High";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "Form already signed.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too Low";
}

void Form::beSigned(const Bureaucrat& b)
{
    if (this->_gradeToSign < b.getGrade())
        throw Form::GradeTooLowException();
    if (this->_isSigned == 1)
        throw Form::AlreadySignedException();
    this->_isSigned = 1;
    std::cout << "Form " << this->_name << " has been signed." << std::endl;
}
