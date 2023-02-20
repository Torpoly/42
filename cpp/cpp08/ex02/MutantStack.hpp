/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:02:57 by rpol              #+#    #+#             */
/*   Updated: 2023/02/21 00:34:17 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>
#include <list>
#include <cstdlib>

template < typename T >
class MutantStack : public std::stack<T> {
	
    public:

		//canon
        MutantStack( void ) : std::stack<T>() {
			
			return;
		};

		MutantStack( const MutantStack<T> & to_copy ) : std::stack<T>( to_copy ) {
            
			*this = to_copy;
			return;
        };
		
		MutantStack & operator=(const MutantStack<T>  & toTheRight ) {
            
			if ( *this == toTheRight )
				return ( *this );
				
			this->c = toTheRight.c;
			return ( *this );
        };
		
        ~MutantStack( void ) {

			return;
		};
		//end canon
        
        typedef typename  std::deque<T>::iterator iterator;
		
        iterator	begin() {
			
            return ( this->c.begin() );
        }
		
        iterator	end() {
			
            return ( this->c.end() );
        }
};

#endif