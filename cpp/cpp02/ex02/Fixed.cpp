/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:15:20 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 22:49:57 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_bits = 8;

Fixed::Fixed( void ) :_fixed(0) {
	
}

Fixed::Fixed( const Fixed & src ) {
	
	*this = src;
}

Fixed::Fixed( const float n ){
	
	this->_fixed = (int)roundf(n * (1 << this->_bits));
}

Fixed::Fixed( const int n ){
	
	this->_fixed = (n * (1 << this->_bits));
}
		
Fixed::~Fixed( void ) {

}

Fixed& 	Fixed::operator=( const Fixed & rhs) {
	
	this->_fixed = rhs.getRawBits();
	return *this;
}

bool 					Fixed::operator>( Fixed const & rhs) const {
	
	if (this->getRawBits() > rhs.getRawBits())
		return ( true );
	else
		return ( false );
}

bool 					Fixed::operator<( Fixed const & rhs) const {
	
	if (this->getRawBits() < rhs.getRawBits())
		return ( true );
	else
		return ( false );
}

bool 					Fixed::operator>=( Fixed const & rhs) const {
	
	if (this->getRawBits() >= rhs.getRawBits())
		return ( true );
	else
		return ( false );
}

bool 					Fixed::operator<=( Fixed const & rhs) const {
	
	if (this->getRawBits() <= rhs.getRawBits())
		return ( true );
	else
		return ( false );
}

bool 					Fixed::operator==( Fixed const & rhs) const {
	
	if (this->getRawBits() == rhs.getRawBits())
		return ( true );
	else
		return ( false );
}

bool 					Fixed::operator!=( Fixed const & rhs) const {
	
	if (this->getRawBits() != rhs.getRawBits())
		return ( true );
	else
		return ( false );
}

Fixed 					Fixed::operator+( Fixed const & rhs) const {
	
	return ( this->toFloat() + rhs.toFloat() );
}

Fixed					Fixed::operator-( Fixed const & rhs) const {
	
	return ( this->toFloat() - rhs.toFloat() );
}

Fixed 					Fixed::operator*( Fixed const & rhs) const {
	
	return ( this->toFloat() * rhs.toFloat() );
}

Fixed 					Fixed::operator/( Fixed const & rhs) const {
	
	return ( this->toFloat() / rhs.toFloat() );
}

Fixed 					Fixed::operator++( int ) {
	
	Fixed a = *this;
	
	this->setRawBits(this->getRawBits() + 1);
	return ( a );
}

Fixed 					Fixed::operator--( int ) {
	
	Fixed a = *this;
	
	this->setRawBits(this->getRawBits() - 1);
	return ( a );
}

Fixed 					Fixed::operator++( void ) {
	
	this->setRawBits(this->getRawBits() + 1);
	return ( *this );
}

Fixed 					Fixed::operator--( void ) {
	
	this->setRawBits(this->getRawBits() - 1);
	return ( *this );
}

Fixed &			Fixed::min(Fixed & src1, Fixed & src2) {
	
	return ( (src1 < src2) ? src1 : src2 );
}

Fixed &			Fixed::max(Fixed & src1, Fixed & src2) {
	
	return ( (src1 > src2) ? src1 : src2 );
}

const Fixed &	Fixed::min(Fixed const & src1, Fixed const & src2) {
	
	return ( (src1 < src2) ? src1 : src2 );
}

const Fixed &	Fixed::max(Fixed const & src1, Fixed const & src2) {
	
	return ( (src1 > src2) ? src1 : src2 );
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
