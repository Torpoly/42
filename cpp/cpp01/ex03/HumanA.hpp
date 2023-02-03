/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:13:38 by rpol              #+#    #+#             */
/*   Updated: 2023/02/02 22:59:30 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

class HumanA{
	
	public:
	
		HumanA( std::string name , Weapon& type );
		~HumanA( void );

		void 		attack( void ) const ;

	private:
	
		std::string	_name;
		Weapon&		_name_of_weapon;
};

#endif