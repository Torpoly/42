/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:24:07 by rpol              #+#    #+#             */
/*   Updated: 2022/02/17 01:39:04 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fput(char *s)
{
	write(1, s, ft_strlen(s));
	return (0);
}

static void	ft_destroy(t_vars *vars)
{
	fput("BYYYYYYYYYYYYYYYYYYYEEEEEEEEE\n");
	free(vars->name);
	ft_freelk(vars);
	mlx_loop_end(vars->mlx);
    mlx_destroy_window(vars->mlx, vars->win);
    fput("window destroyed\n");
    mlx_destroy_display(vars->mlx);
    fput("display destroyed\n");
    free(vars->mlx);
	fput("HASTA LA VISTA \n");
	exit (0);
}

static int	keypress(int keycode, t_vars *vars)
{
	if (keycode == 0x0051)
		return (vars->a -= 30, ft_draw(vars));
	if (keycode == 0x0045)
		return (vars->a += 30, ft_draw(vars));
	if (keycode == 0x0057)
		return (vars->movex -= 20, ft_draw(vars));
	if (keycode == 0x0053)
		return (vars->movex += 20, ft_draw(vars));
	if (keycode == 0x0041)
		return (vars->movey -= 20, ft_draw(vars));
	if (keycode == 0x0044)
		return (vars->movey += 20, ft_draw(vars));
	if (keycode == 0x005a)
		return (vars->alt += 0.1, ft_draw(vars));
	if (keycode == 0x0058)
		return (vars->alt -= 0.1, ft_draw(vars));
	if (keycode == 0x0046)
		return (vars->zoom += 1, ft_draw(vars));
	if (keycode == 0x0052)
		return (vars->zoom -= 1, ft_draw(vars));
	if (keycode == 0xff1b)
		return (ft_destroy(vars), 0);
	return (0);
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
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	if (vars.win == 0)
		return (write(1, "BYEBYE\n", 7), 1);
	mlx_loop(vars.mlx);
}
