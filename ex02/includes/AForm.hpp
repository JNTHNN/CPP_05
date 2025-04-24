/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:29:05 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/19 12:13:11 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
	public:
		AForm();
		AForm(const std::string name);
		AForm(const std::string name, unsigned int grade);
		AForm(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		AForm(const AForm& copied);
		AForm& operator=(const AForm& base);
		virtual ~AForm();

		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	AlreadySignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		std::string				getName() const;
		bool					isSigned() const;
		unsigned int			getGradeToSign() const;
		unsigned int			getGradeToExecute() const;
		virtual void			execute(Bureaucrat const & executor) const = 0;

		void						beSigned(const Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& o, AForm& f);

#endif

