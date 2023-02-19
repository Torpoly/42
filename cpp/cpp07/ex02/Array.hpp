/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:43:13 by rpol              #+#    #+#             */
/*   Updated: 2023/02/19 11:31:01 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template< typename T >
class Array {
	
	public:
	
		//canon
		Array ( void ) : _array( NULL ), _size( 0 ) {
			
			return;
		};
		
		Array ( const Array & to_copy ) {
			
			this->_array = new T[ to_copy.size() ];
			*this = to_copy;
			return;
		};
		
		

		Array &		operator=( const Array & toTheRight )
		{
			if ( this == &toTheRight ) {
				
				return ( *this );
			}
			
			delete [] this->_array;
			this->_array = new T[ toTheRight.size() ];
			this->_size = toTheRight.size();

			for ( size_t index = 0; index < _size; index++ ) {
				
				this->_array[ index ] = toTheRight._array[ index ];
			}
			return ( *this );
		};
		
		~Array ( void ) {
			
			delete [] this->_array;
			return;
		};
		//end of canon
		
		Array ( size_t size ) :
			
			_array( new T[size] ),
			_size( size ) {
			
			return;
		};
		
		T &	operator[]( size_t index ) {

			if ( index < this->_size ) {
				
				return ( this->_array[ index ] );
			} else {
				throw ( Array::indexOutOfBounds() );
			}

		};

		size_t	size( void ) const {
			
			return (this->_size);
		};

		class indexOutOfBounds : public std::exception {
			
			public:
			
				virtual const char * what (void) const throw() {
					
					return ( "Index is out of array bounds !" );
				}
		};
		
		private:
		
			T * 	_array;
			
			size_t 	_size;
			
};

template<typename T>
std::ostream & operator<<( std::ostream & o, Array<T> & toTheRight ) {
	
	for( size_t index = 0; index < toTheRight.size(); ++index ) {
		
		o << "Array[ "<< index << " ] = " << toTheRight[ index ] << std::endl;
	}
	return o;
};

#endif