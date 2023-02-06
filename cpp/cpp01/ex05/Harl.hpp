/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:22:57 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 18:08:37 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Harl{
	
	public:
	
		Harl( void );
		~Harl( void );
		
		void	complain( std::string level );

	private:
	
		void debug( void );
		
		void info( void );
		
		void warning( void );
		
		void error( void );
};

#endif