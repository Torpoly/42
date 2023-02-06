/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:32:56 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 23:42:22 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void );
ClapTrap::ClapTrap( std::string name );
ClapTrap::ClapTrap( const ClapTrap & to_copy );
ClapTrap::~ClapTrap( void );

ClapTrap & 	ClapTrap::operator=( ClapTrap const & rhs ) {
	
	
}
void		ClapTrap::attack(const std::string& target);
void 		ClapTrap::takeDamage(unsigned int amount);
void 		ClapTrap::beRepaired(unsigned int amount);