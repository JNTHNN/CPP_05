/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:42:23 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/24 09:31:39 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	// std::cout << this->_target << " has " << this->getName() << " name and need a grade equal or higher than " << this->getGradeToExecute();
    // std::cout << " to be execute and higher or equal to " << this->getGradeToSign() << " to be signed." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copied): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = copied._target;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& base)
{
	if (this != &base)
		this->_target = base._target;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->isSigned() == 0)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "Drill drill drill" << std::endl;
	/*	Initialisation du générateur random	*/
	srand((unsigned int) time(NULL));
	if (rand() % 2 == 0)
		std::cout << "Then, informs that " << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}
