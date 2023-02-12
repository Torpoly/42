/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:38 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 00:00:21 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//canon
WrongAnimal::WrongAnimal( void ) {

	this->_type = "WrongAnimal";
	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal & to_copy ) {
	*this = to_copy;
}

WrongAnimal & WrongAnimal::operator=( const WrongAnimal & rhs ) {
	
	this->_type = rhs._type;
	return ( *this ); 
}

WrongAnimal::~WrongAnimal( void ) {

	return ;
}

void WrongAnimal::makeSound( void ) const {
	
	std::cout << "*Making WrongAnimal noises*" << std::endl;
}
const std::string & WrongAnimal::getType( void ) const {
	
	return ( this->_type );
}