/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:54:48 by rpol              #+#    #+#             */
/*   Updated: 2022/06/19 16:25:50 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	ft_startt(t_global *global, int i)
{
	global->strt = rtime(0);
	while (++i < global->nb_philo)
	{
		if (pthread_create(&global->id[i], NULL, &routine,
				(void *)&global->philo[i]))
		{
			while (--i >= 0)
				pthread_join(global->id[i], NULL);
			return (stp("FAILED TO CREATE THREAD"));
		}
	}
	i = -1;
	while (++i < global->nb_philo)
	{
		if (pthread_join(global->id[i], NULL))
		{
			return (stp("FAILED TO JOIN THREAD"));
		}
	}
	return (0);
}

int	dead(t_philo *philo)
{
	int	strt;
	int	t;

	strt = philo->global->strt;
	t = rtime(strt);
	pthread_mutex_lock(&philo->global->m_dead);
	if (philo->global->dead == 1)
	{
		pthread_mutex_unlock(&philo->global->m_dead);
		return (1);
	}
	else if ((t - philo->last_meal) > (philo->global->tt_die))
	{
		pthread_mutex_lock(&philo->global->m_write);
		philo->global->dead = 1;
		printf("%d %d died\n", t, philo->id);
		pthread_mutex_unlock(&philo->global->m_write);
		pthread_mutex_unlock(&philo->global->m_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->global->m_dead);
	return (0);
}

int	ft_wait(t_philo *philo, int wait, int status)
{
	int	startt;

	startt = rtime(philo->global->strt);
	if (status == EAT)
	{
		if (message(philo, EAT))
			return (1);
	}
	while ((rtime(philo->global->strt) - startt) < wait)
	{
		usleep(100);
		if (dead(philo))
			return (1);
	}
	if (status == EAT)
	{
		if (freeforks(philo))
			return (1);
	}
	else
	{
		if (message(philo, THINK))
			return (1);
	}
	return (0);
}

int	takefork(t_philo *philo, int i)
{
	if ((i == 0 && (philo->id % 2) == 0) || (i == 1 && (philo->id % 2) != 0))
	{
		pthread_mutex_lock(&philo->lfork->m_fork);
		if (philo->lfork->fork == 1)
		{
			philo->lfork->fork = 0;
			pthread_mutex_unlock(&philo->lfork->m_fork);
			return (message(philo, FORK), 1);
		}
		pthread_mutex_unlock(&philo->lfork->m_fork);
	}
	if ((i == 1 && (philo->id % 2) == 0) || (i == 0 && (philo->id % 2) != 0))
	{
		pthread_mutex_lock(&philo->rfork->m_fork);
		if (philo->rfork->fork == 1)
		{
			philo->rfork->fork = 0;
			pthread_mutex_unlock(&philo->rfork->m_fork);
			return (message(philo, FORK), 1);
		}
		pthread_mutex_unlock(&philo->rfork->m_fork);
	}
	return (0);
}

void	*routine(void *p)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		i = 0;
		while (i < 2)
		{	
			i += takefork(philo, i);
			if (dead(philo))
				return (NULL);
		}
		if (ft_wait(philo, philo->global->tt_eat, EAT))
			return (NULL);
		if (ft_wait(philo, philo->global->tt_sleep, SLEEP))
			return (NULL);
	}
}
