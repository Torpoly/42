/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:31:39 by rpol              #+#    #+#             */
/*   Updated: 2022/02/17 01:33:33 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_2d(t_vars *v, int x, int y, double b)
{
	t_map	*map;
	double	px;
	double	py;
	double	z;
	double	a;

	map = v->m3;
	a = (((double)v->a * 3.1415926535) / 180);
	b = (((double)120 * 3.1415926535) / 180);
	while (map != NULL)
	{
		px = map->x + v->winy;
		py = map->y + v->winy;
		printf("__x:%d__y:%d__", map->x, map->y);
		z = (double)map->z * v->alt;
		x = (int)((px * cos(a)) + (py * cos(a + b)) + (z * cos(a - b)));
		map->rx = (x * v->zoom) + v->movex;
		y = (int)((px * sin(a)) + (py * sin(a + b)) + (z * sin(a - b)));
		map->ry = (y * v->zoom) + v->movey;
		printf("__rx:%d__ry:%d__\n", x, y);
		printf("__rx:%d__ry:%d__\n", map->rx, map->ry);
		map = map->next;
	}
	return (0);
}

/*static int	img_put_pixel(int x, int y, t_vars *v)
{
	char	*adrtmp;
	int		lsz;
	int		bitsz;

	adrtmp = v->adr;
	lsz = *v->lsz;
	bitsz = *v->bitsz;
	if (x >= 0 && y >= 0 && x <= v->size && y <= v->size)
	{
		adrtmp += (y * lsz + (x * ((bitsz) / 8)));
		*(unsigned int *)adrtmp = (unsigned int)v->stdc;
	}
	return (0);
}*/

static int	ft_bsh(t_vars *v, t_map *m0, t_map *m1)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = m1->rx - m0->rx;
	dy = m1->ry - m0->ry;
	x = m0->rx;
	y = m0->ry;
	p = 2 * dy - dx;
	while (x < m1->rx)
	{
		if (p >= 0)
		{
			//img_put_pixel(x++, y++, v);
			mlx_pixel_put(v->mlx, v->win, x++, y++, v->stdc);
			p = p + (2 * dy) - (2 * dx);
		}
		else
		{
			//img_put_pixel(x++, y, v);
			mlx_pixel_put(v->mlx, v->win, x++, y++, v->stdc);
			p = p + 2 * dy;
		}
	}
	return (0);
}

static int	ft_draw2d(t_vars *v)
{
	t_map	*m;

	m = v->m3;
	v->topl = v->m3;
	while (m->next != NULL)
	{
		if (m->y > 0)
		{
			ft_bsh(v, m, v->topl);
			v->topl = v->topl->next;
		}
		if (m->x < v->winx)
			ft_bsh(v, m, m->next);
		m = m->next;
	}
	return (0);
}

int	ft_draw(t_vars *v)
{
	ft_2d(v, 0, 0, 0);
	printf("icccciiii\n");
	//v->img = mlx_new_image(v->mlx, 800, 800);
	printf("icccciiii1\n");
	//v->adr = mlx_get_data_addr(v->img, v->bitsz, v->lsz, v->endi);
	printf("icccciiii2\n");
	ft_draw2d(v);
	printf("icccciiii3\n");
	//mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	//mlx_destroy_image(v->mlx, v->img);
	return (1);
}
