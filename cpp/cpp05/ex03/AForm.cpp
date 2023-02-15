/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:19:59 by rpol              #+#    #+#             */
/*   Updated: 2023/02/14 23:47:42 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//canon
AForm::AForm( void ) : _name( "A4" ) , _isSigned( false ), _gradeToSign( 1 ), _gradeToExecute( 150 ) {
	
	return;
}

AForm::AForm( const AForm & to_copy ) :
	
	_name( to_copy.getName() ),
	_isSigned( to_copy.getIfSigned() ),
	_gradeToSign( to_copy.getGradeToSign() ),
	_gradeToExecute( to_copy.getGradeToExecute() ) {

	return;
}

AForm & AForm::operator=( const AForm & toTheRight ) {

	std::string * namePTR = ( std::string * )&this->_name;
	unsigned int * gradeToSignPTR = ( unsigned int * )&this->_gradeToSign;
	unsigned int * gradeToExecutePTR = ( unsigned int * )&this->_gradeToExecute;
	
	*namePTR = toTheRight.getName();
	this->_isSigned = toTheRight.getIfSigned();
	*gradeToSignPTR = toTheRight.getGradeToSign();
	*gradeToExecutePTR = toTheRight.getGradeToExecute();
	return ( *this );
}

AForm::~AForm( void ) {

	return;
}

const char*	AForm::GradeTooHighException::what( void ) const throw() {
	
	return ("Grade is too high !");
}

const char*	AForm::GradeTooLowException::what( void ) const throw() {

	return ("Grade is too low !");
}

const char*	AForm::FormNotSignedException::what( void ) const throw() {

	return ("Form is not signed !");
}

unsigned int	AForm::_isGoodGrade( unsigned int gradeTo ) {

	int grade = 1;
	try {
		
		if ( gradeTo < HIGHEST_POSSIBLE_GRADE ) {
		
			grade = 1;
			throw ( AForm::GradeTooHighException() );
		}
		else if ( gradeTo > LOWEST_POSSIBLE_GRADE ) {
		
			grade = 150;
			throw ( AForm::GradeTooLowException() );
		}
		else
			return ( gradeTo );
	}
	catch (std::exception & e) {
		
		std::cout << e.what() << std::endl;
	}
	return ( grade ) ;
}

AForm::AForm( const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute )  :

	_name( name ),
	_isSigned( false ),
	_gradeToSign( _isGoodGrade( gradeToSign ) ),
	_gradeToExecute( _isGoodGrade( gradeToExecute ) ) {
	
	return;
}

std::string	AForm::getName( void ) const {

	return ( this->_name );
}

bool 		AForm::getIfSigned( void ) const {

	return ( this->_isSigned );
}

unsigned int 		AForm::getGradeToSign( void ) const {

	return ( this->_gradeToSign );
}

unsigned int 		AForm::getGradeToExecute( void ) const {

	return ( this->_gradeToExecute );
}

bool	AForm::beSigned( const Bureaucrat & bureaucratTringToSign ) {

	try {
		if ( this->_isSigned )
			return ( false );
		if ( bureaucratTringToSign.getGrade() > this->_gradeToSign)
			throw ( AForm::GradeTooLowException() );
		else {
			
			this->_isSigned = true;
			return ( true );
		}
	}
	catch (std::exception & e) {
		
		std::cout << e.what() << std::endl;
		return ( false );
	}
}

bool	AForm::execute( Bureaucrat const & executor ) const {

	try {
		if ( !( this->_isSigned ) )
			throw ( AForm::FormNotSignedException() );
		if ( executor.getGrade() > this->_gradeToExecute)
			throw ( AForm::GradeTooLowException() );
		else {
			
			_executeAction();
			return ( true );
		}
	}
	catch (std::exception & e) {
		
		std::cout << e.what() << std::endl;
		return ( false );
	}
}

std::ostream & operator<<( std::ostream & o, AForm const & toTheRight ) {
	
	o << toTheRight.getName() << ", is a" << ( toTheRight.getIfSigned() ? " signed" : "n unsigned" )
	<< " AForm with a grade to sign at " << toTheRight.getGradeToSign() << ", and grade to execute at "
	<< toTheRight.getGradeToExecute();
	return o;
}
