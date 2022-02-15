/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:52:51 by rpol              #+#    #+#             */
/*   Updated: 2022/02/15 18:46:47 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

static void	ft_freelk(t_vars *vars)
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

static void	ft_getrel(t_vars *vars, t_map *map, int px, int py)
{
	fput("3a\n");
	map->x = px;
	map->y = py;
	map->z = ft_atoip(vars);
	printf("__relx %d rely  %d_ \n", map->x, map->y);
	fput("3b\n");
	if (vars->posx == vars->winx)
	{
		vars->posx = 0;
		vars->posy++;
		vars->l = vars->l->next;
		vars->s = vars->l->s;
	}
	else
		vars->posx++;
}

static int	ft_initstk(t_vars *vars)
{
	t_map	*m;

	fput("2\n");
	vars->err = 0;
	vars->stdc = 0x00FFFF;
	vars->posx = 0;
	vars->posy = 0;
	vars->a = 0;
	vars->l = vars->tab;
	fput(vars->tab->s);
	vars->s = vars->l->s;
	fput(vars->s);
	fput("2a\n");
	m = malloc(sizeof(t_map));
	if (!m)
		return (vars->err = 1, 0);
	fput("2b\n");
	ft_getrel(vars, m, vars->posx, vars->posy);
	fput("2c\n");
	m->c = vars->stdc;
	m->next = NULL;
	vars->map = m;
	return (1);
}

int	ft_linkinit(t_vars *vars)
{
	t_map	*map;

	fput("1\n");
	if (!ft_initstk(vars))
		return (0);
	fput("1\n");
	map = vars->map;
	vars->topl = map;
	while (vars->err == 0 && vars->posy < vars->winy)
	{
		fput("loop\n");
		map->next = malloc(sizeof(t_map));
		if (!map->next)
			return (ft_freelk(vars), 0);
		map = map->next;
		printf("%d %d_____ %d %d \n", vars->posx, vars->winx, vars->posy, vars->winy);
		ft_getrel(vars, map, (float)vars->posx, (float)vars->posy);
		map->c = vars->stdc;
	}
	map->next = NULL;
	fput("end link init\n");
	return (1);
}
