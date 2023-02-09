/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:33:04 by rpol              #+#    #+#             */
/*   Updated: 2023/02/09 01:35:39 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

enum status {
	DEAD,
	ALIVE	
};

class ClapTrap{
	
	public:
	
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap & src );
		ClapTrap & 	operator=( ClapTrap const & rhs );
		~ClapTrap( void );

		
		void		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

	protected:

		std::string	_name;
	
		int			_hit_points;

		int			_energy_points;
		
		int			_attack_damage;
};

#endif
