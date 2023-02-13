/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:38 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 00:24:03 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//canon
WrongAnimal::WrongAnimal( void ) {

	std::cout << "Default WrongAnimal constructor called" << std::endl;
	this->_type = "WrongAnimal";
	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal & to_copy ) {

	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	*this = to_copy;
}

WrongAnimal & WrongAnimal::operator=( const WrongAnimal & rhs ) {
	
	this->_type = rhs._type;
	return ( *this ); 
}

WrongAnimal::~WrongAnimal( void ) {

	std::cout << "Default WrongAnimal destructor called" << std::endl;
	return ;
}

void WrongAnimal::makeSound( void ) const {
	
	std::cout << "*Making WrongAnimal noises*" << std::endl;
}
const std::string & WrongAnimal::getType( void ) const {
	
	return ( this->_type );
}