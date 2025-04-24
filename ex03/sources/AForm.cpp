/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:08:48 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/18 13:35:49 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(): _name("Default"), _gradeToSign(150), _gradeToExecute(150)
{
    this->_isSigned = false;
    return;
}

AForm::AForm(const std::string name): _name(name), _gradeToSign(150), _gradeToExecute(150)
{
    this->_isSigned = false;
    return;
}

AForm::AForm(const std::string name, unsigned int grade): _name(name), _gradeToSign(grade), _gradeToExecute(150)
{
    this->_isSigned = false;
    if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
        throw AForm::GradeTooHighException();
    if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
        throw AForm::GradeTooLowException();
        
}

AForm::AForm(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    this->_isSigned = 0;
    if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
        throw AForm::GradeTooHighException();
    if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copied): _name(copied._name), _gradeToSign(copied._gradeToSign), _gradeToExecute(copied._gradeToExecute)
{
    this->_isSigned = copied._isSigned;
    return;
}

AForm::~AForm()
{
    return;
}

/*	GETTERS	*/

std::string	AForm::getName(void) const
{
    return this->_name;
}

bool	AForm::isSigned(void) const
{
    return this->_isSigned;
}

unsigned int	AForm::getGradeToSign(void) const
{
    return this->_gradeToSign;
}

unsigned int	AForm::getGradeToExecute(void) const
{
    return this->_gradeToExecute;
}

/*	OPERATORS	*/

AForm&	AForm::operator=(const AForm& base)
{
    if (this != &base)
        this->_isSigned = base._isSigned;
    return *this;
}

std::ostream&	operator<<(std::ostream& o, AForm& f)
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

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too High";
}

const char* AForm::AlreadySignedException::what() const throw()
{
    return "Form already signed.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too Low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form not signed.";
}
void AForm::beSigned(const Bureaucrat& b)
{
    if (this->_gradeToSign < b.getGrade())
        throw AForm::GradeTooLowException();
    if (this->_isSigned == 1)
        throw AForm::AlreadySignedException();
    this->_isSigned = 1;
    std::cout << "Form " << this->_name << " has been signed." << std::endl;
}
