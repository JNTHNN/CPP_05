/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:37:40 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/10 12:34:31 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
	public:
		Form();
		Form(const std::string name);
		Form(const std::string name, unsigned int grade);
		Form(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		Form(const Form& copied);
		Form& operator=(const Form& base);
		~Form();

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

		std::string			getName() const;
		bool					isSigned() const;
		unsigned int			getGradeToSign() const;
		unsigned int			getGradeToExecute() const;

		void						beSigned(const Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& o, const Form& f);

#endif
