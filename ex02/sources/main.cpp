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
#include <iostream>

int main(void)
{
    // Création des bureaucrates
    Bureaucrat highRank("HighRank", 1);
    Bureaucrat midRank("MidRank", 50);
    Bureaucrat lowRank("LowRank", 150);

    // Création des formulaires
    ShrubberyCreationForm shrubbery("");
    RobotomyRequestForm robotomy("Target");
    PresidentialPardonForm pardon("Criminal");

    // Test 1 : Exécution réussie d'un ShrubberyCreationForm
	std::cout << "\n\033[35mTest 1: ShrubberyCreationForm - HighRank\033[0m" << std::endl;
	highRank.signForm(shrubbery);
	highRank.executeForm(shrubbery);

    // Test 2 : Signature réussie d'un RobotomyRequestForm mais pas d'exécution (grade low)
	std::cout << "\n\033[35mTest 2: RobotomyRequestForm - MidRank\033[0m" << std::endl;
	midRank.signForm(robotomy);
	midRank.executeForm(robotomy);

    // Test 3 : Exécution réussie d'un PresidentialPardonForm
	std::cout << "\n\033[35mTest 3: PresidentialPardonForm - HighRank\033[0m" << std::endl;
	highRank.signForm(pardon);
	highRank.executeForm(pardon);

    // Test 4 : Échec de signature par un grade insuffisant
	std::cout << "\n\033[35mTest 4: ShrubberyCreationForm - LowRank (échec de signature)\033[0m" << std::endl;
	lowRank.signForm(shrubbery);

    // Test 5 : Échec d'exécution par un grade insuffisant
	std::cout << "\n\033[35mTest 5: PresidentialPardonForm - MidRank (échec d'exécution)\033[0m" << std::endl;
	midRank.executeForm(pardon);

    return 0;
}
