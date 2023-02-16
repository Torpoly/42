/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:36:53 by rpol              #+#    #+#             */
/*   Updated: 2023/02/16 17:10:27 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>

enum typeInput {
	
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER	

};

class Conversion {

	public:

		//canon
		Conversion( void );
		Conversion( const Conversion & to_copy );
		Conversion & operator=( const Conversion & toTheRight );
		virtual ~Conversion( void );

		Conversion( std::string input );
		
		
		void				printTheStuff( void ) const;

		std::string 		getInput( void ) const;

		char				getInputType( void ) const;
		

	private:
	
		std::string			_input;

		char				_inputType;
		
		
		void				_whatIsType( void );
		

		bool 				_isChar( void ) const;

		bool 				_isInt( void ) const;

		bool 				_isFloat( void ) const;

		bool 				_isDouble( void ) const;
		
		
		void				_castChar( void ) const;

		void				_castInt( void ) const;

		void				_castFloat( void ) const;

		void				_castDouble( void ) const;
		
		
		void				_printChar( char const c ) const;
		
		void				_printInt( int const n ) const;

		void				_printFloat( float const f ) const;

		void				_printDouble( double const d ) const;

		void				_printOther( void ) const;

		void				_nani( void ) const;

};

#endif