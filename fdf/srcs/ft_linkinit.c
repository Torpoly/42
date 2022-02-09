/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:52:51 by rpol              #+#    #+#             */
/*   Updated: 2022/02/07 18:01:05 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_freelk(t_vars *vars)
{
	t_map	*m;

	while (vars->map->next != NULL)
	{
		m = vars->map;
		vars->map = vars->map->next;
		free(m);
	}
	free(vars->map);
}
int ft_getalt(int x, int y, t_vars *vars)
{
	//get the alt dep on the position
}

size_t ft_getcol(int x, int y, t_vars *vars)
{
	//need to see if , if , then hex to unsigned else srdc
}

static t_map	*ft_initstk(t_vars *vars)
{
	t_map	*m;

	vars->err = 1;
	vars->stdc = 0;
	m = malloc(sizeof(t_map));
	if (!m)
		return (vars->err = 0, 0);
	m->x = 0;
	m->y = 0;
	m->z = ft_getalt(m->x, m->y, vars);
	m->c = ft_getcol(m->x, m->y, vars);
	vars->map = m;
	return (1);
}

int	ft_linkinit(t_vars *vars)
{
	t_map	*map;

	vars->map = ft_initstk(vars);
	map = vars->map;
	while (vars->err != 0)
	{
		map->next = malloc(sizeof(t_map));
		if (!map->next)
			return (ft_freelk(map), 0);
		map = map->next;
		map->x = (int)ft_atoi(sa[i]);
		map->y = truc;
		map->c = ft_getcol(map->x, map->y);
	}
	map->next = NULL;
	return (1);
}
