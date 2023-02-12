/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:17:45 by rpol              #+#    #+#             */
/*   Updated: 2023/02/12 23:56:13 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//canon
Animal::Animal( void ) {

	this->_type = "Animal";
	return ;
}

Animal::Animal( const Animal & to_copy ) {
	*this = to_copy;
}

Animal & Animal::operator=( const Animal & rhs ) {
	
	this->_type = rhs._type;
	return ( *this ); 
}

Animal::~Animal( void ) {

	return ;
}

void Animal::makeSound( void ) const {
	
	std::cout << "*Making Animal noises*" << std::endl;
}
const std::string & Animal::getType( void ) const {
	
	return ( this->_type );
}