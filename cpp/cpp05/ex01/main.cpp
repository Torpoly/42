/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:18:50 by rpol              #+#    #+#             */
/*   Updated: 2023/02/14 23:33:14 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main ( void ) {

	std::cout << "---BUREAUCRATS TESTS-------------------------" << std::endl;
	std::cout << std::endl;


	Bureaucrat Ron("Ron", 2);

	std::cout << Ron << std::endl;
	Ron.incrementGrade();
	std::cout << Ron << std::endl;
	Ron.incrementGrade();
	std::cout << Ron << std::endl;


	std::cout << std::endl;


	Bureaucrat Andy("Andy", 149);

	std::cout << Andy << std::endl;
	Andy.decrementGrade();
	std::cout << Andy << std::endl;
	Andy.decrementGrade();
	std::cout << Andy << std::endl;

	
	std::cout << std::endl;

	Bureaucrat Andycopy(Andy);
	Ron = Andy;
	std::cout << Ron << std::endl;
	std::cout << Andycopy << std::endl;


	std::cout << std::endl;
	
	
	Bureaucrat Leslie("Leslie", 0);

	std::cout << Leslie << std::endl;


	std::cout << std::endl;


	Bureaucrat April("April", 151);

	std::cout << April << std::endl;


	std::cout << std::endl;
	std::cout << "---FORMS TESTS-------------------------" << std::endl;
	std::cout << std::endl;
	
	
	std::cout << "__Good form____" << std::endl;
	Form paper( "paper", 1, 150);
	std::cout << paper << std::endl;

	std::cout << std::endl;


	std::cout << "__Bad form1_0_0__" << std::endl;
	Form form1( "form1", 0, 0);
	std::cout << form1 << std::endl;

	std::cout << std::endl;


	std::cout << "__Bad form2_151_151__" << std::endl;
	Form form2( "form2", 151, 151);
	std::cout << form2 << std::endl;

	std::cout << std::endl;

	std::cout << "__Bad form3_0_151__" << std::endl;
	Form form3( "form3", 0, 151);
	std::cout << form3 << std::endl;
	
	std::cout << "__Bad form4_151_0__" << std::endl;
	Form form4( "form4", 151, 0);
	std::cout << form4 << std::endl;


	std::cout << std::endl;
	std::cout << "---BUREAUCRATS AND FORMS TESTS-------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "__Andy and paper__" << std::endl;
	std::cout << paper << std::endl;
	std::cout << Andy << std::endl;
	Andy.signForm(paper);
	
	std::cout << std::endl;

	std::cout << "__Leslie and paper__" << std::endl;
	std::cout << paper << std::endl;
	std::cout << Leslie << std::endl;
	Leslie.signForm(paper);

	std::cout << std::endl;

	std::cout << "__Leslie and already signed paper__" << std::endl;
	std::cout << paper << std::endl;
	std::cout << Leslie << std::endl;
	Leslie.signForm(paper);
	
	std::cout << std::endl;

	return ( EXIT_SUCCESS );
}