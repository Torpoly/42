/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:25:48 by rpol              #+#    #+#             */
/*   Updated: 2023/02/20 22:36:07 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

class  Span {

	public:
		
		//canon
		Span( const Span & to_copy );
		Span & operator=( const Span & toTheRight );
		~Span( void );

		Span( size_t N );	

		void			addNumber( const int number );

		void			addRange( const int rangeStart, const int rangeEnd );
		
		long			shortestSpan( void ) const ;
		
		long			longestSpan( void ) const ;

		void			print( void ) const;


	private:
		
		//canon
		Span( void );
		
		std::vector<int> _container;
		
		size_t _size;

		
};


#endif