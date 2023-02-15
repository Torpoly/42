/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:36:59 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 16:37:41 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
//canon
Intern::Intern( void ) {
	
	return;
}
		
Intern::Intern( const Intern & to_copy )  {
	
	*this = to_copy;
	return;
}

Intern & Intern::operator=( const Intern & toTheRight )  {
	
	if ( this == &toTheRight )
		return ( *this );
	return ( *this );
}

Intern::~Intern( void ) {
	
	return;
}

std::string const Intern::_printCreation( std::string const form, std::string const target ) const {
	
	std::cout << "Intern creates " << form
	<< " form, targeting " << target << std::endl;
	return ( target );
}

AForm *	Intern::makeForm( std::string const form, std::string const target ) const {

	std::string formList[3] = { "presidential pardon", "robotomy request", "shrubbery creation"};
	int FORM = PRESIDENTIAL_PARDON;
	while (FORM <= SHRUBBERY_CREATION) {
		
		if ( formList[FORM] == form )
			break;
		FORM++;
	}
	switch (FORM) {
	
		case PRESIDENTIAL_PARDON :
		
			return ( new PresidentialPardonForm( _printCreation( form, target ) ) );
		
		case ROBOTOMY_REQUEST :
		
			return ( new RobotomyRequestForm( _printCreation( form, target ) ) );

		case SHRUBBERY_CREATION :
		
			return ( new ShrubberyCreationForm( _printCreation( form, target ) ) );
	
		default :
			
			std::cout << "Intern could not create " << form << " because it does not exist !" << std::endl;
		
	}
	return ( NULL );
}