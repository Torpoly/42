/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:03:52 by rpol              #+#    #+#             */
/*   Updated: 2022/06/16 17:06:53 by rpol             ###   ########.fr       */
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
typedef struct s_philo
{
	int			id;
	long long	srt;
	long long	last_meal;
	int			status;
	int			forks;
	int			meals;
}				t_philo;


/*IN PHILO.C*/

int			philo(int ac, char **av);

/*IN PARSING.C*/

int			parsing(int ac, char **av);

int			ft_strlen(char *str);

void		stp(char *str);

long int	ft_atoi(const char *s);

int			isnum(char *str);



#endif