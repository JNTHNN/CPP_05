/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:17:20 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/24 15:29:42 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
	// std::cout << this->_target << " has " << this->getName() << " name and need a grade equal or higher than " << this->getGradeToExecute();
    // std::cout << " to be execute and higher or equal to " << this->getGradeToSign() << " to be signed." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copied): AForm("PreseidentialPardonForm", 25, 5)
{
	this->_target = copied._target;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& base)
{
	if (this != &base)
		this->_target = base._target;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (this->isSigned() == 0)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beebletrox." << std::endl;
}
