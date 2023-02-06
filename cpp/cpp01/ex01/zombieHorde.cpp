/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:45:40 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 17:29:38 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	
	Zombie *UnitedHordeOfZombies = new Zombie[N];
	int i = 0;
	while(i < N)
	{
		UnitedHordeOfZombies[i].name_zombie(name);
		i++;
	}
	return (UnitedHordeOfZombies);
}