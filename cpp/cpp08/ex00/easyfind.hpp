/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:51:45 by rpol              #+#    #+#             */
/*   Updated: 2023/02/19 22:16:15 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


template < typename T >
typename T::iterator easyfind( T & container, int value) {
    
	typename T::iterator it = std::find( container.begin(), container.end(), value );
	
    if ( it != container.end() ) {
        
		return ( it );
		
    } else {
		
        throw std::runtime_error( "Did not find value in container" );
    }
}


#endif