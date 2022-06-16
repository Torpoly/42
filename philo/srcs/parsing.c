/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:47:54 by rpol              #+#    #+#             */
/*   Updated: 2022/06/13 15:30:53 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int ac, char **av)
{
	int	i;

	i = ac;
	if (ac < 5)
		return (stp("Not enought arguments"), 1);
	if (ac > 6)
		return (stp("Too much arguments"), 1);
	while (i-- > 1)
	{
		if (isnum(av[i]) || ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < 0)
			return (stp("Invalid argument"), 1);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	stp(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

long int	ft_atoi(const char *s)
{
	long long int	i;
	int				sign;
	long long int	nb;

	sign = 1;
	i = 0;
	nb = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '-')
		sign = -1;
	if (sign == -1 || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = (nb * 10) + (s[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}