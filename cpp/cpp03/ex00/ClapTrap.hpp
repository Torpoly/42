/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:33:04 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 23:40:21 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

class ClapTrap{
	
	public:
	
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap & to_copy );
		
		~ClapTrap( void );

		ClapTrap & 	operator=( ClapTrap const & rhs );
		
		void		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

	private:

		std::string	_name;
	
		int			_hit_points;

		int			_energy_points;
		
		int			_attack_damage;
};

#endif
