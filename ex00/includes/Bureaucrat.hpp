/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:18:37 by jgasparo          #+#    #+#             */
/*   Updated: 2024/12/19 12:03:36 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <iostream>

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
		
		
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat& b);

#endif
