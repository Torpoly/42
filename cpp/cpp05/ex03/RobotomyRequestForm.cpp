/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:28:56 by rpol              #+#    #+#             */
/*   Updated: 2023/02/15 03:23:31 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//canon
RobotomyRequestForm::RobotomyRequestForm( void ) :

	AForm( "RobotomyRequestForm",
			ROBOTOMY_GRADE_TO_SIGN,
			ROBOTOMY_GRADE_TO_EXECUTE ),
	_target( "default" ) {

	return;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & to_copy ) :
	
	AForm ( to_copy ),
	_target( to_copy.getTarget() ) {
		
	return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm & toTheRight ) {

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

RobotomyRequestForm::~RobotomyRequestForm( void ) {

	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) :
	
	AForm( "RobotomyRequestForm",
			ROBOTOMY_GRADE_TO_SIGN,
			ROBOTOMY_GRADE_TO_EXECUTE ),
	_target( target ) {

	return;
}

void				RobotomyRequestForm::_executeAction( void ) const {
	
	std::cout << "*drilling noises* DZZZZZZZZ DZZZZZZZZZZ DZZZZZZZZZ *drilling noises*" << std::endl;
	srand(time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomy has failed" << std::endl;
}

std::string		RobotomyRequestForm::getTarget( void ) const {

	return ( this->_target );
}

std::ostream & operator<<( std::ostream & o, RobotomyRequestForm const & toTheRight ) {

	o << toTheRight.getName() << ", is a" << ( toTheRight.getIfSigned() ? " signed" : "n unsigned" )
	<< " Form targeting " << toTheRight.getTarget() << " with a grade to sign at " 
	<< toTheRight.getGradeToSign() << ", and grade to execute at " << toTheRight.getGradeToExecute();
	return o;
}