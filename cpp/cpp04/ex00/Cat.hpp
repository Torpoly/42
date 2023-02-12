/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:20:23 by rpol              #+#    #+#             */
/*   Updated: 2023/02/12 23:38:45 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	
	public:
	
		//canon
		Cat( void );
		Cat( const Cat & to_copy );
		Cat & operator=( const Cat & rhs );
		virtual ~Cat( void );
		
		
		virtual void makeSound( void ) const;

};

#endif