/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:30 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 02:51:50 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	
	public:
	
		//canon
		Dog( void );
		Dog( const Dog & to_copy );
		Dog & operator=( const Dog & rhs );
		virtual ~Dog( void );
		
		
		virtual void 		makeSound( void ) const;

		void 				setIdea( unsigned int i, std::string idea );	
		
		const std::string	getIdea( unsigned int i ) const;

		void				printBrainAdresse( void ) const;
	
	private:

		Brain * _Brain;
		
};

#endif