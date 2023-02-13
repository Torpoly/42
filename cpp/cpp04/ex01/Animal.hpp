/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:17:40 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 02:52:57 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <cstdlib>

class Animal {
	
	public:
	
		//canon
		Animal( void );
		Animal( const Animal & to_copy );
		Animal & operator=( const Animal & rhs );
		virtual ~Animal( void );
		
		
		virtual void 				makeSound( void ) const;
		
		virtual const std::string &	getType( void ) const;

		virtual void 				setIdea( unsigned int i, std::string idea ) = 0;	
		
		virtual const std::string	getIdea( unsigned int i ) const = 0;
	
	
	protected:
	
		std::string _type;
	
};

#endif