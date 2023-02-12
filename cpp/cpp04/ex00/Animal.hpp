/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:17:40 by rpol              #+#    #+#             */
/*   Updated: 2023/02/12 01:36:50 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

class Animal {
	
	public:
	
		//canon
		Animal( void );
		Animal( const Animal & to_copy );
		Animal & operator=( const Animal & rhs );
		virtual ~Animal( void );
		
		
		virtual void makeSound( void ) const;
		
		virtual const std::string & getType( void ) const;
	
	
	protected:
	
		std::string _type;
	
};

#endif