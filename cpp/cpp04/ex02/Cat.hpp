/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:23 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 03:42:26 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	
	public:
	
		//canon
		Cat( void );
		Cat( const Cat & to_copy );
		Cat & operator=( const Cat & rhs );
		virtual ~Cat( void );
		
		
		virtual void		makeSound( void ) const;

		const std::string &	getType( void ) const;
		
		void 				setIdea( unsigned int i, std::string idea );	
		
		const std::string	getIdea( unsigned int i ) const;

		void				printBrainAdresse( void ) const;
	
	private:

		Brain * _Brain;

};

#endif