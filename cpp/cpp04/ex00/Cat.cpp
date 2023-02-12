/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:20 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 00:18:07 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//canon
Cat::Cat( void ) : Animal() {

	std::cout << "Default Cat constructor called" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat( const Cat & to_copy ) : Animal( to_copy ) {
	
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = to_copy;
}

Cat & Cat::operator=( const Cat & rhs ) {
	
	this->_type = rhs._type;
	return ( *this ); 
}

Cat::~Cat( void ) {

	std::cout << "Default Cat destructor called" << std::endl;
	return ;
}

void Cat::makeSound( void ) const {
	
	std::cout << "* =^..^= Miaou *" << std::endl;
}