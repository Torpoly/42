/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:38:56 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 17:51:36 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	
	int N = 5;
	int i = 0;

	Zombie*		UnitedHordeOfZombies = zombieHorde( N, "hoarder_" );
	
	while (i < N)
	{
		UnitedHordeOfZombies[i].announce();
		i++;
	}

	delete [] UnitedHordeOfZombies;
	
	return (EXIT_SUCCESS);
}