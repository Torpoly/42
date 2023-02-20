/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:25:43 by rpol              #+#    #+#             */
/*   Updated: 2023/02/20 22:55:58 by rpol             ###   ########.fr       */
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

	try {
	
		if ( this->_container.size() < this->_size) {
		
			this->_container.push_back( number );		
			
		} else {
		
			throw std::runtime_error( "Can't add new number because size is reached" );
		}
	} catch ( const std::runtime_error & e ) {
		
        std::cerr << e.what() << std::endl;
    }
}

void Span::addRange(const int rangeStart, const int rangeEnd) {
	
	try {
		
		int rangeSpan = std::abs( rangeEnd - rangeStart );
		
    	if ( this->_container.size() + ( rangeSpan + 1 ) <= this->_size ) {
			
    	    std::vector<int> range;
			int index = rangeStart;
			
			while( 1 ) {
				
				range.push_back( index );

				if ( index == rangeEnd )
					break;
				
				if ( rangeStart < rangeEnd )
					index++;
				else
					index--;
			}
			
    	    this->_container.insert( this->_container.end(), range.begin(), range.end() );
    	} else {
			
    	    throw std::runtime_error("Can't add the range because size will be reached");
			
    	}
	} catch ( const std::runtime_error & e ) {
		
        std::cerr << e.what() << std::endl;
    }
}	

long	Span::shortestSpan( void ) const {

	if ( this->_container.size() < 2) {
		
            return ( 0 );	
    }
	
	std::vector<int> tmp( this->_container );
	std::sort(tmp.begin(), tmp.end());

	long min_diff = LONG_MAX;

    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; ++it) {
        int diff = *(it + 1) - *it;
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    return ( min_diff );
}

long	Span::longestSpan( void ) const {
	
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
