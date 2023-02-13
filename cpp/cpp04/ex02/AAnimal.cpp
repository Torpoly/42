/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:17:45 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 03:35:39 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//canon
AAnimal::AAnimal( void ) {

	std::cout << "Default AAnimal constructor called" << std::endl;
	this->_type = "AAnimal";
	return ;
}

AAnimal::AAnimal( const AAnimal & to_copy ) {

	std::cout << "Copy AAnimal constructor called" << std::endl;
	*this = to_copy;
}

AAnimal & AAnimal::operator=( const AAnimal & rhs ) {
	
	this->_type = rhs._type;
	return ( *this ); 
}

AAnimal::~AAnimal( void ) {

	std::cout << "Default AAnimal destructor called" << std::endl;
	return ;
}

void	AAnimal::makeSound( void ) const {
	
	std::cout << "*Making AAnimal noises*" << std::endl;
}
const	std::string & AAnimal::getType( void ) const {
	
	return ( this->_type );
}