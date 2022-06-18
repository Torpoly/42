/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:54:48 by rpol              #+#    #+#             */
/*   Updated: 2022/06/18 23:36:29 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	else if ((t - philo->last_meal) > philo->global->tt_die)
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

int	ft_wait(t_philo *philo, int wait)
{
	int	startt;
	int	strt;

	strt = philo->global->strt;
	startt = rtime(strt);
	while ((rtime(strt) - startt) < wait)
	{
		usleep(100);
		if (dead(philo))
			return (1);
	}
	return (0);
}

int	takefork(t_philo *philo, int i)
{
	if (i == 0)
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
	else if (i == 1)
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
		if (message(philo, THINK))
			return (NULL);
		while (i < 2)
		{	
			i += takefork(philo, i);
			if (dead(philo))
				return (NULL);
		}
		philo->last_meal = rtime(philo->global->strt);
		if (message(philo, EAT))
			return (NULL);
		if (ft_wait(philo, philo->global->tt_eat))
			return (NULL);
		if (freeforks(philo))
			return (NULL);
		if (ft_wait(philo, philo->global->tt_sleep))
			return (NULL);
	}
}
