/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:38:56 by rpol              #+#    #+#             */
/*   Updated: 2023/02/02 00:23:20 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	
	int N = 21;
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