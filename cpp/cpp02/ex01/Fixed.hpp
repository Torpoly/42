/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:15:25 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 22:44:19 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cstdlib>
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

		Fixed & 				operator=( Fixed const & rhs );

		bool 					operator>( Fixed const & rhs) const;

		bool 					operator<( Fixed const & rhs) const;

		bool 					operator>=( Fixed const & rhs) const;
	
		bool 					operator<=( Fixed const & rhs) const;

		bool 					operator==( Fixed const & rhs) const;

		bool 					operator!=( Fixed const & rhs) const;

		Fixed 					operator+( Fixed const & rhs) const;

		Fixed 					operator-( Fixed const & rhs) const;

		Fixed 					operator*( Fixed const & rhs) const;

		Fixed 					operator/( Fixed const & rhs) const;

		Fixed 					operator++( int n );

		Fixed 					operator--( int n );

		Fixed 					operator++( void );

		Fixed 					operator--( void );

		static Fixed &			min(Fixed & src1, Fixed & src2);

		static Fixed &			max(Fixed & src1, Fixed & src2);

		static const Fixed &	min(Fixed const & src1, Fixed const & src2);

		static const Fixed &	max(Fixed const & src1, Fixed const & src2);

		float			toFloat( void ) const;

		int				toInt( void ) const;
		
		int				getRawBits( void ) const;
		
		void			setRawBits( int const raw );
};

/*IN FIXED.CPP*/

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif