/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:36:54 by rpol              #+#    #+#             */
/*   Updated: 2023/03/25 01:48:59 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <iostream>

class RPN {
	
	public:
		
		//////// Orthodox Canonical Form /////////
		RPN( void );
		RPN( const RPN &toCopy);
		RPN& operator=( const RPN &toTheRight );
		~RPN( void );

		/////// METHODS /////////
		double evaluate( const std::string &expression );

};

#endif