/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:18:27 by rpol              #+#    #+#             */
/*   Updated: 2022/02/07 16:48:59 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int

int	ft_parsing(int ac, char **av, t_vars *vars)
{
	vars->err = 0;
	vars->winx = 0;
	vars->winy = 0;
	if (ac != 2)
		return (fput("ERROR WRONG ARGUMENTS\n"));
	if (ft_strlen(av[1]) == 0)
		return (fput("ERROR EMPTY NAME\n"));
	vars->fd = open(av[1], O_RDONLY);
	if (vars->fd < 1)
		return (fput("ERROR CANT OPEN FILE\n"));
	vars->name = ft_strjoin("fdf ", av[1]);
	vars->tab = gnl(vars);
	if (vars->err == 1)
		return (ft_free_array(vars->tab, vars->winy), fput("ERROR MAP\n"));
	return (1);
}
