/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:21:19 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 00:02:56 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
	
	public:
	
		//canon
		WrongDog( void );
		WrongDog( const WrongDog & to_copy );
		WrongDog & operator=( const WrongDog & rhs );
		virtual ~WrongDog( void );
		
		
		void makeSound( void ) const;

};

#endif