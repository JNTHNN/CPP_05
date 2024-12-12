/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:18:40 by jgasparo          #+#    #+#             */
/*   Updated: 2024/12/12 13:17:39 by jgasparo         ###   ########.fr       */
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
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copied)
{
	*this = copied;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

/*	need to fix -> _name pas assigné a la copie	*/
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& base)
{
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