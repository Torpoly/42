/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:39:13 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 17:26:26 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

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