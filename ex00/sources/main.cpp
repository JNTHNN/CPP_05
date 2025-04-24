/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:18:42 by jgasparo          #+#    #+#             */
/*   Updated: 2025/04/24 10:20:53 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    // Test 1 : Création de bureaucrates avec des grades valides
    std::cout << "\n\033[35mTest 1: Création de bureaucrates avec des grades valides\033[0m" << std::endl;
    try
    {
        Bureaucrat highRank("HighRank", 1);
        Bureaucrat midRank("MidRank", 75);
        Bureaucrat lowRank("LowRank", 150);

        std::cout << highRank << std::endl;
        std::cout << midRank << std::endl;
        std::cout << lowRank << std::endl;
        std::cout << "\033[32m==== SUCCESS ====\033[0m" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[31m==== FAIL ====\033[0m" << std::endl;
    }

    // Test 2 : Tentative de création avec un grade trop élevé (0)
    std::cout << "\n\033[35mTest 2: Tentative de création avec un grade trop élevé (0)\033[0m" << std::endl;
    try
    {
        Bureaucrat invalidHigh("InvalidHigh", 0);
        std::cout << invalidHigh << std::endl;
        std::cout << "\033[32m==== SUCCESS ====\033[0m" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[31m==== FAIL ====\033[0m" << std::endl;
    }

    // Test 3 : Tentative de création avec un grade trop bas (151)
    std::cout << "\n\033[35mTest 3: Tentative de création avec un grade trop bas (151)\033[0m" << std::endl;
    try
    {
        Bureaucrat invalidLow("InvalidLow", 151);
        std::cout << invalidLow << std::endl;
        std::cout << "\033[32m==== SUCCESS ====\033[0m" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[31m==== FAIL ====\033[0m" << std::endl;
    }

    // Test 4 : Augmentation et diminution de grade
    std::cout << "\n\033[35mTest 4: Augmentation et diminution de grade\033[0m" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 2);
        Bureaucrat employee("Employee", 149);

        std::cout << boss << std::endl;
        std::cout << employee << std::endl;

        boss.gradeUp();
        std::cout << "Après gradeUp : " << boss << std::endl;

        employee.gradeDown();
        std::cout << "Après gradeDown : " << employee << std::endl;

        std::cout << "\033[32m==== SUCCESS ====\033[0m" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[31m==== FAIL ====\033[0m" << std::endl;
    }

    // Test 5 : Dépassement des limites lors de gradeUp et gradeDown
    std::cout << "\n\033[35mTest 5: Dépassement des limites lors de gradeUp et gradeDown\033[0m" << std::endl;
    try
    {
        Bureaucrat top("Top", 1);
        Bureaucrat bottom("Bottom", 150);

        std::cout << top << std::endl;
        std::cout << bottom << std::endl;

        top.gradeUp(); // Devrait lever une exception
        bottom.gradeDown(); // Devrait lever une exception

        std::cout << "\033[32m==== SUCCESS ====\033[0m" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException: " << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[31m==== FAIL ====\033[0m" << std::endl;
    }

    return 0;
}