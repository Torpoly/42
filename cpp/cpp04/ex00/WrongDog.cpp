/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:21:01 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 00:05:15 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

//canon
WrongDog::WrongDog( void ) : WrongAnimal() {

	this->_type = "WrongDog";
	return ;
}

WrongDog::WrongDog( const WrongDog & to_copy ) : WrongAnimal( to_copy ) {
	*this = to_copy;
}

WrongDog & WrongDog::operator=( const WrongDog & rhs ) {
	
	this->_type = rhs._type;
	return ( *this ); 
}

WrongDog::~WrongDog( void ) {

	return ;
}

void WrongDog::makeSound( void ) const {
	
	std::cout << "* ˁ˚ᴥ˚ˀ WrongWouaf *" << std::endl;
}