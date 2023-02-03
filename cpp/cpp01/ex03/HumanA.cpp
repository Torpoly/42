/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:13:31 by rpol              #+#    #+#             */
/*   Updated: 2023/02/02 22:59:40 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name , Weapon& name_of_weapon ) : _name( name ), _name_of_weapon( name_of_weapon ) {
	
	return ;
}
		
HumanA::~HumanA( void ) {
	
	return ;
}

		
void 		HumanA::attack( void ) const {

	std::cout << this->_name << " attacks with their " << this->_name_of_weapon.getType() << std::endl;
}