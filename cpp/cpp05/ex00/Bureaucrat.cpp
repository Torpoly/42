/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:18:41 by rpol              #+#    #+#             */
/*   Updated: 2023/02/14 23:49:47 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//canon
Bureaucrat::Bureaucrat( void ) : _name("dwight") , _grade(150) {
	
	return;
}

Bureaucrat::Bureaucrat( const Bureaucrat & to_copy ) : _name(to_copy.getName()), _grade( to_copy.getGrade() ) {

	return;
}

Bureaucrat & Bureaucrat::operator=( const Bureaucrat & toTheRight ) {

	std::string * namePTR = ( std::string * )&this->_name;
	
	*namePTR = toTheRight.getName();
	this->_grade = toTheRight.getGrade();
	return ( *this );
}

Bureaucrat::~Bureaucrat( void ) {

	return;
}

Bureaucrat::Bureaucrat( const std::string name, const unsigned int grade )  : _name(name), _grade(grade) {
	
	try {
		
		if ( grade < HIGHEST_POSSIBLE_GRADE ) {
		
			this->_grade = 1;
			throw ( Bureaucrat::GradeTooHighException() );
		}
		else if ( grade > LOWEST_POSSIBLE_GRADE ) {
		
			this->_grade = 150;
			throw ( Bureaucrat::GradeTooLowException() );
		}
		else
			this->_grade = grade;
	}
	catch (std::exception & e) {
		
		std::cout << e.what() << std::endl;
	}
	return;
}

void	Bureaucrat::incrementGrade( void ) {
	
	try {
		
		if ( this->_grade == HIGHEST_POSSIBLE_GRADE )
			throw ( Bureaucrat::GradeTooHighException() );
		else
			this->_grade--;
	}
	catch (std::exception & e) {
		
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade( void ) {

	try {
		
		if ( this->_grade == LOWEST_POSSIBLE_GRADE )
			throw ( Bureaucrat::GradeTooLowException() );
		else
			this->_grade++;
	}
	catch (std::exception & e) {
		
		std::cout << e.what() << std::endl;
	}
}

unsigned int	Bureaucrat::getGrade( void ) const {
	
	return ( this->_grade );
}

std::string	Bureaucrat::getName( void ) const {
	
	return ( this->_name );
}

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw() {
	
	return ("Grade is too high !");
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw() {

	return ("Grade is too low !");
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & toTheRight ) {
	
	o << toTheRight.getName() << ", is a Bureaucrat with grade at " << toTheRight.getGrade();
	return o;
}
	