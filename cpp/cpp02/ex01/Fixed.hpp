/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:15:25 by rpol              #+#    #+#             */
/*   Updated: 2023/02/05 20:51:48 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	
	private:
	
		int					_fixed;
		
		int const static	_bits;
	
	public:
	
		Fixed( void );
		Fixed( const int n );
		Fixed( const float n );
		Fixed( const Fixed & to_copy );
		
		~Fixed( void );

		Fixed & 		operator=( Fixed const & rhs );

		float			toFloat( void ) const;

		int				toInt( void ) const;
		
		int				getRawBits( void ) const;
		
		void			setRawBits( int const raw );
};

/*IN FIXED.CPP*/

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif