/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:54:23 by jgasparo          #+#             */
/*   Updated: 2025/04/24 09:10:25 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include <iostream>

int main(void)
{
    {
        Intern gerard;

        // Test 1 : Création d'un formulaire valide
		std::cout << "\n\033[35mTest 1 : Création d'un formulaire valide\033[0m" << std::endl;
        AForm* form = gerard.makeForm("robotomy request", "Bender");
        if (form)
        {
            std::cout << *form << std::endl;

            // Test 2 : Signature du formulaire
			std::cout << "\n\033[35mTest 2 : Signature du formulaire\033[0m" << std::endl;
            Bureaucrat manager("Manager", 50);
            manager.signForm(*form);

            // Test 3 : Exécution du formulaire
			std::cout << "\n\033[35mTest 3 : Exécution du formulaire\033[0m" << std::endl;
            Bureaucrat executor("Executor", 45);
            executor.executeForm(*form);

            delete form;
        }
    }

	// Test 4 : Tentative de création d'un formulaire invalide
	std::cout << "\n\033[35mTest 4: Tentative de création d'un formulaire invalide\033[0m" << std::endl;
	try
	{
		Intern	herve;
		AForm* form = herve.makeForm("unknown form", "Target");
		if (form)
		delete form;
	}
	catch (const Intern::FormNotFound& e)
	{
		std::cerr << e.what() << std::endl;
	}

    return 0;
}
