/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:39:13 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 17:43:05 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie{
	
	public:
	
		Zombie( std::string name );
		~Zombie( void );
		
		void	announce( void );

	private:
	
		std::string _name;
};

/*IN NEWZOMBIES.CPP*/

Zombie			*newZombie( std::string name );

/*IN RANDOMCHUMP.CPP*/

void			randomChump( std::string name );

#endif