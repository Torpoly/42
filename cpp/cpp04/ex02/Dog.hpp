/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:30 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 03:43:54 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	
	public:
	
		//canon
		Dog( void );
		Dog( const Dog & to_copy );
		Dog & operator=( const Dog & rhs );
		virtual ~Dog( void );
		
		
		virtual void 		makeSound( void ) const;

		const std::string &	getType( void ) const;

		void 				setIdea( unsigned int i, std::string idea );	
		
		const std::string	getIdea( unsigned int i ) const;

		void				printBrainAdresse( void ) const;
	
	private:

		Brain * _Brain;
		
};

#endif