/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:17:45 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 00:18:36 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//canon
Animal::Animal( void ) {

	std::cout << "Default Animal constructor called" << std::endl;
	this->_type = "Animal";
	return ;
}

Animal::Animal( const Animal & to_copy ) {

	std::cout << "Copy Animal constructor called" << std::endl;
	*this = to_copy;
}

Animal & Animal::operator=( const Animal & rhs ) {
	
	this->_type = rhs._type;
	return ( *this ); 
}

Animal::~Animal( void ) {

	std::cout << "Default Animal destructor called" << std::endl;
	return ;
}

void Animal::makeSound( void ) const {
	
	std::cout << "*Making Animal noises*" << std::endl;
}
const std::string & Animal::getType( void ) const {
	
	return ( this->_type );
}