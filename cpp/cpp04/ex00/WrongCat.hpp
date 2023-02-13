/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:54 by rpol              #+#    #+#             */
/*   Updated: 2023/02/13 14:36:40 by rpol             ###   ########.fr       */
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
		
		
		void makeSound( void ) const;

};

#endif