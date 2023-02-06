/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:15:20 by rpol              #+#    #+#             */
/*   Updated: 2023/02/05 20:52:46 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_bits = 8;

Fixed::Fixed( void ) :_fixed(0) {
	
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed( const Fixed & to_copy ) {
	
	std::cout << "Copy constructor called" <<std::endl;
	*this = to_copy;
}
		
Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;
}

Fixed& 	Fixed::operator=( const Fixed & rhs ) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = rhs.getRawBits();
	return *this;
}
		
int		Fixed::getRawBits( void ) const {
	
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}
		
void	Fixed::setRawBits( int const raw ) {
	
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}