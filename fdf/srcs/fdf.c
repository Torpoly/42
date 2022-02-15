/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:24:07 by rpol              #+#    #+#             */
/*   Updated: 2022/02/15 18:46:51 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_draw(t_vars *vars, int x, int y)
{
	t_map	*map;
	float	px;
	float	py;
	float	z;
	float	a;

	printf("__relx %d rely  %d_ \n", vars->map->x, vars->map->y);
	map = vars->topl;
	a = (float)vars->a;
	while (map != NULL)
	{
		px = (float)map->x;
		py = (float)map->y;
		z = (float)map->z;
		x = (((int)(((px * cosf(a)) + (py * cosf(a + 120)) + (z * cosf(a - 120)))) * 15) + (vars->size / 3));
		y = (((int)(((px * sinf(a)) + (py * sinf(a + 120)) + (z * sinf(a - 120)))) * 15) + (100));
		printf("__relx %d rely  %d_ \n", x, y);
		mlx_pixel_put(vars->mlx, vars->win, x, y, map->c);
		map = map->next;
	}
	return (1);
}

int	fput(char *s)
{
	write(1, s, ft_strlen(s));
	return (0);
}

static int	turn(int keycode, t_vars *vars)
{
	if (keycode == 0x0061)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = mlx_new_window(vars->mlx, vars->size, vars->size, vars->name);
		vars->a += 30;
		ft_draw(vars, 0, 0);
		return (0);
	}
	return (1);
}

static int	escape(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		vars->win = 0;
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (!ft_parsing(ac, av, &vars))
		return (0);
	fput("2\n");
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.size, vars.size, vars.name);
	fput("here\n");
	ft_draw(&vars);
	mlx_key_hook(vars.win, escape, &vars);
	mlx_key_hook(vars.win, turn, &vars);
	if (vars.win == 0)
		return (write(1, "BYEBYE\n", 7), 1);
	mlx_loop(vars.mlx);
}
