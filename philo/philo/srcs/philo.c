/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:04:43 by rpol              #+#    #+#             */
/*   Updated: 2022/06/18 22:52:42 by rpol             ###   ########.fr       */
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
	t_global	*global;

	global = malloc(sizeof(t_global));
	if (!global)
		return (stp("ERROR MALLOC"));
	if (linkinit(ac, av, global))
		return (free(global), 1);
	global->id = malloc(sizeof(pthread_t) * global->nb_philo);
	if (!global->id)
		return (freeg(global), stp("ERROR MALLOC OF T ID"));
	ft_startt(global, -1);
	free(global->id);
	freeg(global);
	return (0);
}

int	freeg(t_global *global)
{
	int	i;

	i = global->nb_philo;
	while (--i >= 0)
		pthread_mutex_destroy(&global->fork[i].m_fork);
	pthread_mutex_destroy(&global->m_dead);
	pthread_mutex_destroy(&global->m_write);
	free(global->fork);
	free(global->philo);
	free(global);
	return (0);
}

int	message(t_philo *philo, int status)
{
	int	t;

	t = rtime(philo->global->strt);
	pthread_mutex_lock(&philo->global->m_write);
	pthread_mutex_lock(&philo->global->m_dead);
	if (philo->global->dead == 1)
	{
		pthread_mutex_unlock(&philo->global->m_dead);
		pthread_mutex_unlock(&philo->global->m_write);
		return (1);
	}
	if (status == THINK)
		printf("%d %d is thinking\n", t, philo->id);
	else if (status == FORK)
		printf("%d %d has taken a fork\n", t, philo->id);
	else if (status == EAT)
		printf("%d %d is eating\n", philo->last_meal, philo->id);
	else if (status == SLEEP)
		printf("%d %d is sleeping\n", t, philo->id);
	pthread_mutex_unlock(&philo->global->m_dead);
	pthread_mutex_unlock(&philo->global->m_write);
	return (0);
}

int	rtime(int strt)
{
	struct timeval	tv;
	int				t;

	gettimeofday(&tv, NULL);
	t = ((tv.tv_usec) / 1000);
	return ((t - strt));
}
