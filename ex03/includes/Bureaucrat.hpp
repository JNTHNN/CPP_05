/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:30:13 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/19 12:00:21 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& copied);
		Bureaucrat&	operator=(const Bureaucrat& base);
		~Bureaucrat();

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;

		void	gradeUp();
		void	gradeDown();
		void	signForm(AForm& f) const;
		void	executeForm(const AForm& form);
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat& b);

#endif
