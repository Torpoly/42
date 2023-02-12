/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:17:40 by rpol              #+#    #+#             */
/*   Updated: 2023/02/12 23:58:32 by rpol             ###   ########.fr       */
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
		
		
		virtual void makeSound( void ) const;
		
		const std::string & getType( void ) const;
	
	
	protected:
	
		std::string _type;
	
};

#endif