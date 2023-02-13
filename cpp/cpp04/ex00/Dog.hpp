/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:30 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 03:44:18 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
	
	public:
	
		//canon
		Dog( void );
		Dog( const Dog & to_copy );
		Dog & operator=( const Dog & rhs );
		virtual ~Dog( void );
		
		
		virtual void makeSound( void ) const;
		
};

#endif