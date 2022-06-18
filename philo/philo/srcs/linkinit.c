/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:03:17 by rpol              #+#    #+#             */
/*   Updated: 2022/06/18 23:04:34 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	linkinit(int ac, char **av, t_global *global)
{
	global->nb_philo = ft_atoi(av[1]);
	global->tt_die = ft_atoi(av[2]);
	global->tt_eat = ft_atoi(av[3]);
	global->tt_sleep = ft_atoi(av[4]);
	global->nbt_eat = -1;
	if (ac == 6)
		global->nbt_eat = ft_atoi(av[5]);
	global->fork = malloc(sizeof(t_fork) * global->nb_philo);
	if (!global->fork)
		return (stp("ERROR MALLOC OF FORKS"));
	global->philo = malloc(sizeof(t_philo) * global->nb_philo);
	if (!global->philo)
		return (free(global->fork), stp("ERROR MALLOC OF PHILOS"));
	global->dead = 0;
	if (ft_initphilo(global, -1))
		return (free(global->fork), free(global->philo), 1);
	return (0);
}

int	ft_initphilo(t_global *global, int i)
{
	if (ft_initforks(global, i))
		return (1);
	while (++i < global->nb_philo)
	{
		if (i == 0)
			global->philo[i].lfork = &global->fork[global->nb_philo - 1];
		else
			global->philo[i].lfork = &global->fork[i - 1];
		global->philo[i].rfork = &global->fork[i];
		global->philo[i].id = (i + 1);
		global->philo[i].nb_meals = 0;
		global->philo[i].last_meal = 0;
		global->philo[i].global = global;
	}
	return (0);
}

int	ft_initforks(t_global *global, int i)
{
	if (pthread_mutex_init(&global->m_dead, NULL))
		return (stp("MUTEX INIT ERROR"));
	if (pthread_mutex_init(&global->m_write, NULL))
		return (pthread_mutex_destroy(&global->m_dead), stp("MUTEX ERROR"));
	while (++i < global->nb_philo)
	{
		global->fork[i].fork = 1;
		if (pthread_mutex_init(&global->fork[i].m_fork, NULL))
		{
			pthread_mutex_destroy(&global->m_dead);
			pthread_mutex_destroy(&global->m_write);
			while (--i >= 0)
				pthread_mutex_destroy(&global->fork[i].m_fork);
			return (1);
		}
	}
	return (0);
}

int	freeforks(t_philo *philo)
{
	pthread_mutex_lock(&philo->lfork->m_fork);
	philo->lfork->fork = 1;
	pthread_mutex_unlock(&philo->lfork->m_fork);
	pthread_mutex_lock(&philo->rfork->m_fork);
	philo->rfork->fork = 1;
	pthread_mutex_unlock(&philo->rfork->m_fork);
	philo->nb_meals++;
	if (philo->nb_meals == philo->global->nbt_eat)
		return (1);
	return (0);
}
