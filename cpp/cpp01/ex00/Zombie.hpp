/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:39:13 by rpol              #+#    #+#             */
/*   Updated: 2023/02/01 23:22:19 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Zombie{
	
	public:
	
		Zombie( std::string name );
		~Zombie( void );
		
		void	announce( void );

	private:
	
		std::string _name;
};

/*IN NEWZOMBIE.CPP*/

Zombie			*newZombie( std::string name );

/*IN RANDOMCHUMP.CPP*/

void			randomChump( std::string name );



#endif