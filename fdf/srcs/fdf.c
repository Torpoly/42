/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:24:07 by rpol              #+#    #+#             */
/*   Updated: 2022/02/03 22:32:56 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int fput(char *s)
{
	write(1, s, ft_strlen(s));
	return (0);
}

static int	escape(int keycode, t_vars *vars)
{
	if(keycode == 0xff1b)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_display(vars->mlx);
		vars->win = 0;
		return (0);
	}
	return (1);
}

static int	ft_check(int ac, char *s, t_vars *vars)
{
	if (ac != 2)
		return (fput("ERROR WRONG ARGUMENTS\n"));
	if (ft_strlen(s) == 0)
		return (fput("ERROR EMPTY NAME\n"));
	vars->fd = open(s, O_RDONLY);
	if (fd < 1)
		return (fput("ERROR CANT OPEN FILE\n"));
	vars->name = ft_strjoin("fdf ", s);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars vars;

	if (!ft_check(av[ac -1], &vars))
		return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, vars.name);
	mlx_key_hook(vars.win, escape, &vars);
	if (vars.win == 0)
		return (write(1, "BYEBYE\n", 7), 1);
	mlx_loop(vars.mlx);
}
