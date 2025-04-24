/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:18:42 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/24 10:28:34 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>

int main(void)
{
    std::cout << "********** TESTING FORMS **********" << std::endl;

    // Test 1 : Création d'un formulaire avec des grades valides
    std::cout << "\n\033[35mTest 1: Création d'un formulaire avec des grades valides\033[0m" << std::endl;
    try
    {
        Form form("Form A", 50, 100);
        std::cout << form << std::endl;
        std::cout << "\033[32m==== SUCCESS ====\033[0m" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[31m==== FAIL ====\033[0m" << std::endl;
    }

    // Test 2 : Création d'un formulaire avec un grade de signature trop élevé
    std::cout << "\n\033[35mTest 2: Création d'un formulaire avec un grade de signature trop élevé (0)\033[0m" << std::endl;
    try
    {
        Form form("Form B", 0, 100);
        std::cout << form << std::endl;
        std::cout << "\033[32m==== SUCCESS ====\033[0m" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[31m==== FAIL ====\033[0m" << std::endl;
    }

    // Test 3 : Création d'un formulaire avec un grade d'exécution trop bas
    std::cout << "\n\033[35mTest 3: Création d'un formulaire avec un grade d'exécution trop bas (151)\033[0m" << std::endl;
    try
    {
        Form form("Form C", 50, 151);
        std::cout << form << std::endl;
        std::cout << "\033[32m==== SUCCESS ====\033[0m" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[31m==== FAIL ====\033[0m" << std::endl;
    }

    // Test 4 : Signature d'un formulaire avec un grade insuffisant
    std::cout << "\n\033[35mTest 4: Signature d'un formulaire avec un grade insuffisant\033[0m" << std::endl;
	{
        Bureaucrat employee("Employee", 100);
        Form form("Form D", 50, 50);

        std::cout << employee << std::endl;
        std::cout << form << std::endl;

        employee.signForm(form);
	}

    // Test 5 : Signature réussie d'un formulaire
    std::cout << "\n\033[35mTest 5: Signature réussie d'un formulaire\033[0m" << std::endl;
    {
        Bureaucrat manager("Manager", 40);
        Form form("Form E", 50, 50);

        std::cout << manager << std::endl;
        std::cout << form << std::endl;

        manager.signForm(form);
        std::cout << form << std::endl;
    }
    return 0;
}
