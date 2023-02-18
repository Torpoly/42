/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:43:13 by rpol              #+#    #+#             */
/*   Updated: 2023/02/18 16:22:59 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstdlib>

template< typename T >
void	iter( T Array[], size_t size, void (function)( T const & )) {

	for (size_t index = 0 ; index < size ; index++ ) {
		
		function(Array[ index ]);
	}
}

template< typename T >
void	printIndex( T const & index ) {

	std::cout << index << std::endl;
}

#endif