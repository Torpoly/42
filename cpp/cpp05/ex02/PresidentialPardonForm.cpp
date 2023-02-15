/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:28:43 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 02:01:52 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//canon
PresidentialPardonForm::PresidentialPardonForm( void ) :

	AForm( "PresidentialPardonForm",
			PRESIDENTIAL_GRADE_TO_SIGN,
			PRESIDENTIAL_GRADE_TO_EXECUTE ),
	_target( "default" ) {

	return;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & to_copy ) :
	
	AForm ( to_copy ),
	_target( to_copy.getTarget() ) {
		
	return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm & toTheRight ) {

	std::string * targetPTR = ( std::string * )&this->_target;
	std::string * namePTR = ( std::string * )&this->_name;
	unsigned int * gradeToSignPTR = ( unsigned int * )&this->_gradeToSign;
	unsigned int * gradeToExecutePTR = ( unsigned int * )&this->_gradeToExecute;
	
	*targetPTR = toTheRight.getTarget();
	*namePTR = toTheRight.getName();
	this->_isSigned = toTheRight.getIfSigned();
	*gradeToSignPTR = toTheRight.getGradeToSign();
	*gradeToExecutePTR = toTheRight.getGradeToExecute();
	return ( *this );
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	
	AForm( "PresidentialPardonForm",
			PRESIDENTIAL_GRADE_TO_SIGN,
			PRESIDENTIAL_GRADE_TO_EXECUTE ),
	_target( target ) {

	return;
}

void				PresidentialPardonForm::_executeAction( void ) const {
	
	std::cout << "Informs that " << this->getTarget()
	<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string		PresidentialPardonForm::getTarget( void ) const {

	return ( this->_target );
}

std::ostream & operator<<( std::ostream & o, PresidentialPardonForm const & toTheRight ) {

	o << toTheRight.getName() << ", is a" << ( toTheRight.getIfSigned() ? " signed" : "n unsigned" )
	<< " Form targeting " << toTheRight.getTarget() << " with a grade to sign at " 
	<< toTheRight.getGradeToSign() << ", and grade to execute at " << toTheRight.getGradeToExecute();
	return o;
}
