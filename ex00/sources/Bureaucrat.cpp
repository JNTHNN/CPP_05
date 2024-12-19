/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:18:40 by jgasparo          #+#    #+#             */
/*   Updated: 2024/12/19 12:42:21 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("JohnDoe"), _grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(const std::string name): _name(name)
{
	_grade = 150;
	return;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copied): _name(copied._name), _grade(copied._grade)
{
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& base)
{
	if (this != &base)
		this->_grade = base._grade;
	return *this;
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat& b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return o;
}

const std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Grade too High.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Grade too Low.";
}
