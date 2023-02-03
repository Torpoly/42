/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:13:46 by rpol              #+#    #+#             */
/*   Updated: 2023/02/02 23:00:04 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{
	
	public:
	
		HumanB( std::string name );
		~HumanB( void );

		void 		attack( void ) const ;
		void		setWeapon( Weapon& name_of_weapon);

	private:
	
		std::string	_name;
		Weapon*		_name_of_weapon;
};

#endif