/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:59:23 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/24 15:10:56 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern& copied)
{
	(void)copied;
	return ;
}

Intern& Intern::operator=(const Intern& base)
{
	(void)base;
	return *this;
}

Intern::~Intern(void)
{
	return ;
}

const char* Intern::FormNotFound::what() const throw()
{
	return "Form Not Form, Intern can't work";
}

std::string toLower(const std::string& str)
{
    std::string lowerStr = str;
    for (size_t i = 0; i < str.size(); ++i)
        lowerStr[i] = std::tolower(static_cast<unsigned char>(str[i]));
    return lowerStr;
}

AForm*	Intern::makeForm(const std::string name, const std::string target)
{
	const std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	std::string lowerName = toLower(name);

	size_t	i(0);
	while (i < 3 && lowerName != formNames[i])
		i++;
	
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " + name << std::endl;
			return new PresidentialPardonForm(target);
			break;
		case 1:
			std::cout << "Intern creates " + name << std::endl;
			return new RobotomyRequestForm(target);
			break;
		case 2:
			std::cout << "Intern creates " + name << std::endl;
			return new ShrubberyCreationForm(target);
		default:
			throw FormNotFound();
			break;
	}
}
