/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:45:40 by rpol              #+#    #+#             */
/*   Updated: 2023/02/02 00:00:49 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	
	Zombie *UnitedHordeOfZombies = new Zombie[N];
	int i = 0;
	while(i < N)
	{
		std::string horder_id = name;
		horder_id += std::to_string(i + 1);
		UnitedHordeOfZombies[i].name_zombie(horder_id);
		i++;
	}
	return (UnitedHordeOfZombies);
}