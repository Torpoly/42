/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:11:34 by rpol              #+#    #+#             */
/*   Updated: 2023/02/09 01:42:49 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
	public:
		
		//canon
		ScavTrap( void );
		ScavTrap( const ScavTrap & to_copy );
		ScavTrap &	operator=( ScavTrap const & rhs );
		~ScavTrap( void );
		

		ScavTrap( std::string name );
		
		
		void		attack( const std::string & target) ;
		
		void 		guardGate( void );

};

#endif