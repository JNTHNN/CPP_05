/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:18:42 by jgasparo          #+#    #+#             */
/*   Updated: 2024/12/22 14:28:29 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void)
{
	std::cout << "--------------------------------------" << std::endl;

	try
	{
		std::cout << "********** TRY (BASIC) **********" << std::endl;
		Bureaucrat	boss( "Jeff", 1 );
		Bureaucrat	employe( "Marcel", 149 );

		std::cout << boss << std::endl;
		std::cout << employe << std::endl;

		std::cout << std::endl << "********** SUCCESS (BASIC) **********" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << "********** CATCH (BASIC) **********" << std::endl;
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;
	
	try
	{
		std::cout << "********** TRY (GRADE = 0) **********" << std::endl;
		Bureaucrat	fail( "bob", 0 );

		std::cout << fail << std::endl;
		std::cout << std::endl << "********** SUCCESS (GRADE = 0) **********" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << "********** CATCH (GRADE = 0) **********" << std::endl;
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		std::cout << "********** TRY (GRADE = 151) **********" << std::endl;
		Bureaucrat	fail( "looser", 151 );

		std::cout << fail << std::endl;
		std::cout << std::endl << "********** SUCCESS (GRADE = 151) **********" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << "********** CATCH (GRADE = 151) **********" << std::endl;
		std::cout << e.what() << std::endl << std::endl;
	}
	
	std::cout << "--------------------------------------" << std::endl;

	try
	{
		std::cout << "********** TRY (1 GOOD 1 BAD) **********" << std::endl;
		Bureaucrat	good( "GoodBoy", 19 );
		Bureaucrat	bad( "BadBoy", -42 );

		std::cout << good << std::endl;
		std::cout << bad << std::endl;
		std::cout << std::endl << "********** SUCCESS (1 GOOD 1 BAD) **********" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << "********** CATCH (1 GOOD 1 BAD) **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;

	try
	{
		std::cout << "********** TRY (GRADE UP GRADE DOWN) **********" << std::endl;
		Bureaucrat	boss( "Jeff", 1 );
		Bureaucrat	employe( "Marcel", 149 );

		std::cout << boss << std::endl;
		std::cout << employe << std::endl;

		boss.gradeDown();
		std::cout << boss << std::endl;
		boss.gradeUp();
		std::cout << boss << std::endl;
		employe.gradeDown();
		std::cout << employe << std::endl;
		std::cout << std::endl << "********** SUCCESS (GRADE UP GRADE DOWN) **********" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << "********** CATCH (GRADE UP GRADE DOWN) **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl;
	}
	
	std::cout << "--------------------------------------" << std::endl;
	
	return (0);
}