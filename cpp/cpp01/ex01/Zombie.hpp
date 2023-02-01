/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:39:13 by rpol              #+#    #+#             */
/*   Updated: 2023/02/01 23:54:14 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Zombie{
	
	public:
	
		Zombie( void );
		~Zombie( void );
		
		void	announce( void );
		void	name_zombie( std::string name );

	private:
	
		std::string _name;
};

/*IN ZOMBIEHORDE.CPP*/

Zombie*			zombieHorde( int N, std::string name );

#endif