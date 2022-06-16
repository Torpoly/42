/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:04:43 by rpol              #+#    #+#             */
/*   Updated: 2022/06/13 15:12:10 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (parsing(ac, av))
		return (-1);
	if (philo(ac, av))
		return (-1);
	return (0);
}

int	philo(int ac, char **av)
{
	//t_philo		*philo;
	//t_rules		*rules;
	int i;
	int j;

	//if (linkinit(ac, av, *philo, *rules))

	i = ac;
	j = i + ft_atoi (av[1]);
	write(1, "lifetick\n",9);
	return (j);
}