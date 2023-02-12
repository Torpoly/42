/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:26 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 00:04:04 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//canon
Dog::Dog( void ) : Animal() {

	this->_type = "Dog";
	return ;
}

Dog::Dog( const Dog & to_copy ) : Animal( to_copy ) {
	*this = to_copy;
}

Dog & Dog::operator=( const Dog & rhs ) {
	
	this->_type = rhs._type;
	return ( *this ); 
}

Dog::~Dog( void ) {

	return ;
}

void Dog::makeSound( void ) const {
	
	std::cout << "* ˁ˚ᴥ˚ˀ Wouaf *" << std::endl;
}