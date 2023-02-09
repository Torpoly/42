/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:33:10 by rpol              #+#    #+#             */
/*   Updated: 2023/02/07 16:19:21 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ( void ) {

	ClapTrap steve;
	ClapTrap bob("bob");
	ClapTrap stevecpy(steve);
	
	std::cout << std::endl;
	
	stevecpy.takeDamage(1);
	stevecpy = bob;
	stevecpy.takeDamage(1);

	std::cout << std::endl;
	
	bob.takeDamage(1);
	bob.beRepaired(1);
	bob.attack("a turtle");
	bob.takeDamage(1);
	bob.beRepaired(1);
	bob.takeDamage(1);
	bob.beRepaired(1);
	bob.takeDamage(1);
	bob.beRepaired(1);
	bob.takeDamage(1);
	bob.beRepaired(100);
	bob.attack("an other turtle");
	bob.attack("a sloth");
	bob.attack("an other sloth");
	bob.beRepaired(1);

	std::cout << std::endl;
	
	steve.takeDamage(100);
	steve.attack("a bear");
	steve.beRepaired(100);
	
	return ( EXIT_SUCCESS );
}