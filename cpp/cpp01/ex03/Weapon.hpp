/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:02:08 by rpol              #+#    #+#             */
/*   Updated: 2023/02/02 22:48:12 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
	
	public:
	
		Weapon( std::string type );
		~Weapon( void );

		std::string 	getType( void ) const;
		
		void 			setType( std::string name );

	private:
	
		std::string _type;
};

#endif