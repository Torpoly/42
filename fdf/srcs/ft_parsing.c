/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:18:27 by rpol              #+#    #+#             */
/*   Updated: 2022/02/16 21:30:31 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_freelktab(t_vars *vars)
{
	t_tab	*t;

	while (vars->tab->next != NULL)
	{
		t = vars->tab;
		vars->tab = vars->tab->next;
		free(t);
	}
	free(vars->tab);
}

int	ft_atoip(t_vars *vars)
{
	char	*str;
	int		sign;
	int		nb;

	sign = 1;
	nb = 0;
	str = vars->s;
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	vars->s = str;
	return (nb * sign);
}

int	ft_parsing(int ac, char **av, t_vars *vars)
{
	vars->err = 0;
	vars->winx = 0;
	vars->winy = 0;
	vars->size = 800;
	if (ac != 2)
		return (fput("ERROR WRONG ARGUMENTS\n"));
	if (ft_strlen(av[1]) == 0)
		return (fput("ERROR EMPTY NAME\n"));
	vars->fd = open(av[1], O_RDONLY);
	if (vars->fd < 1)
		return (fput("ERROR CANT OPEN FILE\n"));
	gnl(vars);
	fput("1\n");
	if (vars->err == 1)
		return (ft_freelktab(vars), fput("ERROR MAP\n"));
	if (!ft_linkinit(vars))
		return (ft_freelktab(vars), 0);
	vars->name = ft_strjoinc("fdf ", av[1]);
	return (1);
}
