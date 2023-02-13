/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:43 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 14:39:21 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <cstdlib>

class WrongAnimal {
	
	public:
	
		//canon
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal & to_copy );
		WrongAnimal & operator=( const WrongAnimal & rhs );
		virtual ~WrongAnimal( void );
		
		
		void makeSound( void ) const;
		
		const std::string & getType( void ) const;
	
	
	protected:
	
		std::string _type;
	
};

#endif