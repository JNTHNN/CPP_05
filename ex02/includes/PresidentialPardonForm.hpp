/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:30:15 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/24 13:02:30 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string _target;
	
	public:
		PresidentialPardonForm();
	// ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {} // Appelle un constructeur de AForm
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copied);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& base);

		void	execute(const Bureaucrat& executor) const;
};

#endif
