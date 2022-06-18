/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:03:52 by rpol              #+#    #+#             */
/*   Updated: 2022/06/18 23:12:28 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

/* STRUCTS */

typedef struct s_fork
{
	int				fork;
	pthread_mutex_t	m_fork;
}			t_fork;

typedef struct s_global	t_global;

typedef struct s_philo
{
	int			id;
	t_fork		*lfork;
	t_fork		*rfork;
	int			last_meal;
	int			nb_meals;
	t_global	*global;
}				t_philo;

typedef struct s_global
{
	int				nb_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				nbt_eat;
	t_philo			*philo;
	t_fork			*fork;
	int				dead;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_write;
	pthread_t		*id;
	int				strt;

}				t_global;

typedef enum e_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_status;

/*IN PHILO.C*/

int			philo(int ac, char **av);

int			freeg(t_global *global);

int			message(t_philo *philo, int status);

int			rtime(int strt);

/*IN PARSING.C*/

int			parsing(int ac, char **av);

int			ft_strlen(char *str);

int			stp(char *str);

long int	ft_atoi(const char *s);

int			isnum(char *str);

/*IN LINKINIT.C*/

int			linkinit(int ac, char **av, t_global *global);

int			ft_initphilo(t_global *global, int i);

int			ft_initforks(t_global *global, int i);

int			freeforks(t_philo *philo);

/*IN ROUTINE.C*/

int			ft_startt(t_global *global, int i);

int			dead(t_philo *philo);

int			ft_wait(t_philo *philo, int wait);

int			takefork(t_philo *philo, int i);

void		*routine(void *philo);

#endif