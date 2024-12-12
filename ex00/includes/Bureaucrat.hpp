/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:18:37 by jgasparo          #+#    #+#             */
/*   Updated: 2024/12/12 12:57:21 by jgasparo         ###   ########.fr       */
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

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;
		
		
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat& b);

#endif
