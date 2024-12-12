/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:18:42 by jgasparo          #+#    #+#             */
/*   Updated: 2024/12/12 12:55:25 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a;
	Bureaucrat	b("Jojo");
	Bureaucrat	c("Pipo", 2);
	Bureaucrat	d = c;

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;
	
	return 0;
}