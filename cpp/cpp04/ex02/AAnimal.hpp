/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:17:40 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 03:34:34 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <cstdlib>

class AAnimal {
	
	public:
	
		//canon
		AAnimal( void );
		AAnimal( const AAnimal & to_copy );
		AAnimal & operator=( const AAnimal & rhs );
		virtual ~AAnimal( void );
		
		
		virtual void 				makeSound( void ) const = 0;
		
		virtual const std::string &	getType( void ) const ;
	
	protected:
	
		std::string _type;
	
};

#endif