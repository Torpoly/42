/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:20:08 by rpol              #+#    #+#             */
/*   Updated: 2023/01/30 18:29:42 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int i = 1;
	int j;
	
	if (ac == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else {
		while ( i < ac){
			j = 0;
			while(av[i][j]){
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					av[i][j] -= 32;
				j++;
			}
			std::cout << av[i];
			i++;
		}
	}
	std::cout << std::endl;
	return 0;
}