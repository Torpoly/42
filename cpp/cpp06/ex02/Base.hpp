/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:19:17 by rpol              #+#    #+#             */
/*   Updated: 2023/02/17 11:36:44 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

enum Base_creation {
	
	BASE_A,
	BASE_B,
	BASE_C	

};

class Base {

	public :
	
		virtual ~Base( void );
	
};

#endif