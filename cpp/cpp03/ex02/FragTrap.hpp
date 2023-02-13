/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:00:56 by rpol              #+#    #+#             */
/*   Updated: 2023/02/09 18:05:23 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	
	public:
		
		//canon
		FragTrap( void );
		FragTrap( const FragTrap & to_copy );
		FragTrap &	operator=( FragTrap const & rhs );
		~FragTrap( void );
		

		FragTrap( std::string name );
		
		
		void 		highFivesGuys( void );

};

#endif