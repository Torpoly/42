/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:15:20 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 22:55:41 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_bits = 8;

Fixed::Fixed( void ) :_fixed(0) {
	
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed( const Fixed & src ) {
	
	std::cout << "Copy constructor called" <<std::endl;
	*this = src;
}

Fixed::Fixed( const float n ){
	
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = (int)roundf(n * (1 << this->_bits));
}

Fixed::Fixed( const int n ){
	
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = (n * (1 << this->_bits));
}
		
Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;
}

Fixed& 	Fixed::operator=( const Fixed & rhs) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = rhs.getRawBits();
	return *this;
}

float			Fixed::toFloat( void ) const {
	
	return ((float)this->_fixed / (1 << this->_bits));
}

int				Fixed::toInt( void ) const {
	
	return (this->_fixed / (1 << this->_bits));
}
		
int		Fixed::getRawBits( void ) const {
	
	return this->_fixed;
}
		
void	Fixed::setRawBits( int const raw ) {
	
	this->_fixed = raw;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {
	
	o << rhs.toFloat();
	return o;
}
