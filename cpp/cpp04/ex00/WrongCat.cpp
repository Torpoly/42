/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:49 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 00:25:14 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//canon
WrongCat::WrongCat( void ) : WrongAnimal() {

	std::cout << "Default WrongCat constructor called" << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat( const WrongCat & to_copy ) : WrongAnimal( to_copy ) {

	std::cout << "Copy WrongCat constructor called" << std::endl;
	*this = to_copy;
}

WrongCat & WrongCat::operator=( const WrongCat & rhs ) {
	
	this->_type = rhs._type;
	return ( *this ); 
}

WrongCat::~WrongCat( void ) {
	
	std::cout << "Default WrongCat destructor called" << std::endl;
	return ;
}

void WrongCat::makeSound( void ) const {
	
	std::cout << "* =^..^= WrongMiaou *" << std::endl;
}