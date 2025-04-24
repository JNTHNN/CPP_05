/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:59:16 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/24 12:33:21 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cctype>

class Bureaucrat;
class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& copied);
		~Intern();
		Intern& operator=(const Intern& base);

		AForm*	makeForm(const std::string name, const std::string target);

		class FormNotFound: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

#endif
