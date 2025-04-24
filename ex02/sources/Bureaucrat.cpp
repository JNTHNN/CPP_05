/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:51:47 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/24 10:45:23 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

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
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
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
	return "Grade too High.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too Low.";
}

void	Bureaucrat::gradeDown(void)
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << this->_name << " grade down" << std::endl;
}

void	Bureaucrat::gradeUp(void)
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << this->_name << " grade up" << std::endl;
}

void	Bureaucrat::signForm(AForm& f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << this->_name << " couldn't sign " << f.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
        std::cout << this->_name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
	}

}
