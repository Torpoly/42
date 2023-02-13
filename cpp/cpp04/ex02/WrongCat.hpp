/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:54 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 00:01:38 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	
	public:
	
		//canon
		WrongCat( void );
		WrongCat( const WrongCat & to_copy );
		WrongCat & operator=( const WrongCat & rhs );
		virtual ~WrongCat( void );
		
		
		virtual void makeSound( void ) const;

};

#endif