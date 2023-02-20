/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:25:43 by rpol              #+#    #+#             */
/*   Updated: 2023/02/20 18:16:10 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span( void ) {

	return;
}

Span::Span( const Span & to_copy ) {
	
	*this = to_copy;
	return;
}

Span & Span::operator=( const Span & toTheRight ) {
	
	this->_container = toTheRight._container;
	this->_size = toTheRight._size;
	return ( *this );
}

Span::~Span( void )	{
	
	return;
}

Span::Span( size_t N ) {
	
	this->_container.reserve( N );
	this->_size = N ;
	
	return;
}

void	Span::addNumber( const int number ) {

	if ( this->_container.size() < this->_size) {

		this->_container.push_back( number );		
		
	} else {

		throw std::runtime_error( "Can't add new number because size is reached" );
	}
}

int	Span::shortestSpan( void ) const {

	if ( this->_container.size() < 2) {
		
            return ( 0 );	
    }
	
	std::vector<int> tmp( this->_container );
	std::sort(tmp.begin(), tmp.end());

	int min_diff = INT_MAX;

    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; ++it) {
        int diff = *(it + 1) - *it;
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    return min_diff;
}

int	Span::longestSpan( void ) const {
	
	if ( this->_container.size() < 2) {
		
            return ( 0 );
			
    } else {
		
		return ( *std::max_element(this->_container.begin(), this->_container.end()) 
				- *std::min_element(this->_container.begin(), this->_container.end()) );
	}
}

void	Span::print( void ) const {

	for( std::vector<int>::const_iterator it = this->_container.begin();
			it != this->_container.end() ; ++it ) {
		
		std::cout << *it << std::endl;
	}
}
