/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:18:50 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 16:36:23 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main ( void ) {

	{
		std::cout << std::endl;
		std::cout << "---INTERN, BUREAUCRATS AND PRESIDENTIAL FORM TYPES TESTS-------------------------" << std::endl;
		std::cout << std::endl;
	
		Bureaucrat Andy("Andy", 150);
		std::cout << Andy << std::endl << std::endl;
		Bureaucrat Leslie("Leslie", 1);
		std::cout << Leslie << std::endl << std::endl;
		
		Intern nameLessIntern;
		AForm * steve = nameLessIntern.makeForm( "presidential pardon", "Snowden" );
			
		if ( steve ) {
		
			std::cout << *steve << std::endl;
			
		
			std::cout << std::endl << "__Leslie and steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Leslie << std::endl;
			Leslie.execute( *steve );
			
			
			std::cout << std::endl << "__Andy and sign steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Andy << std::endl;
			Andy.signForm(*steve);
		
		
			std::cout << std::endl << "__Leslie and sign steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Leslie << std::endl;
			Leslie.signForm( *steve );
		
		
			std::cout << std::endl << "__Andy and execute steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Andy << std::endl;
			Andy.execute(*steve);
		
		
			std::cout << std::endl << "__Leslie and execute steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Leslie << std::endl << std::endl;
			Leslie.execute( *steve );
		
			delete steve;
		}
	}
	{
	std::cout << std::endl;
	std::cout << "---INTERN, BUREAUCRATS AND ROBOTOMY TYPES TESTS-------------------------" << std::endl;
	std::cout << std::endl;

	Bureaucrat Andy("Andy", 150);
	std::cout << Andy << std::endl << std::endl;
	Bureaucrat Leslie("Leslie", 1);
	std::cout << Leslie << std::endl << std::endl;
	
	Intern nameLessIntern;
	AForm * steve = nameLessIntern.makeForm( "robotomy request", "Bender" );
	

	if ( steve ) {
		
			std::cout << *steve << std::endl;
			
		
			std::cout << std::endl << "__Leslie and steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Leslie << std::endl;
			Leslie.execute( *steve );
			
			
			std::cout << std::endl << "__Andy and sign steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Andy << std::endl;
			Andy.signForm(*steve);
		
		
			std::cout << std::endl << "__Leslie and sign steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Leslie << std::endl;
			Leslie.signForm( *steve );
		
		
			std::cout << std::endl << "__Andy and execute steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Andy << std::endl;
			Andy.execute(*steve);
		
		
			std::cout << std::endl << "__Leslie and execute steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Leslie << std::endl << std::endl;
			Leslie.execute( *steve );
		
			delete steve;
		}
	}
	{
	std::cout << std::endl;
	std::cout << "---INTERN, BUREAUCRATS AND SCHRUBERRY TYPES TESTS-------------------------" << std::endl;
	std::cout << std::endl;

	Bureaucrat Andy("Andy", 150);
	std::cout << Andy << std::endl << std::endl;
	Bureaucrat Leslie("Leslie", 1);
	std::cout << Leslie << std::endl << std::endl;
	
	Intern nameLessIntern;
	AForm * steve = nameLessIntern.makeForm( "shrubbery creation", "tree" );
	

	if ( steve ) {
		
			std::cout << *steve << std::endl;
			
		
			std::cout << std::endl << "__Leslie and steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Leslie << std::endl;
			Leslie.execute( *steve );
			
			
			std::cout << std::endl << "__Andy and sign steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Andy << std::endl;
			Andy.signForm(*steve);
		
		
			std::cout << std::endl << "__Leslie and sign steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Leslie << std::endl;
			Leslie.signForm( *steve );
		
		
			std::cout << std::endl << "__Andy and execute steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Andy << std::endl;
			Andy.execute(*steve);
		
		
			std::cout << std::endl << "__Leslie and execute steve__" << std::endl << std::endl ;
			std::cout << *steve << std::endl;
			std::cout << Leslie << std::endl << std::endl;
			Leslie.execute( *steve );
		
			delete steve;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "---INTERN, WRONG TYPES TESTS-------------------------" << std::endl;
		std::cout << std::endl;
		
		Intern nameLessIntern;
		AForm * steve;
		steve = nameLessIntern.makeForm( "something", "tree" );

		std::cout << std::endl;
	}
	
	return ( EXIT_SUCCESS );
}