/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:31:39 by rpol              #+#    #+#             */
/*   Updated: 2022/02/18 19:07:33 by rpol             ###   ########.fr       */
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
		px = map->x;
		py = map->y;
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

void	ft_bsh(t_vars *v, t_map *m0, t_map *m1)
{
 
	int dx = abs(m1->rx - m0->rx), sx = m0->rx < m1->rx ? 1 : -1;
	int dy = abs(m1->ry - m0->ry), sy = m0->ry < m1->ry ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;
	int	x, y ;
 
	x = m0->rx;
	y = m0->ry;
  for(;;)
  {
    mlx_pixel_put(v->mlx, v->win, x, y, v->stdc);
    if (x == m1->rx && y == m1->ry) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x += sx; }
    if (e2 < dy) { err += dx; y += sy; }
  }
}

/*static int	ft_bsh(t_vars *v, t_map *m0, t_map *m1)
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
}*/

static int	ft_draw2d(t_vars *v)
{
	t_map	*m;

	m = v->m3->next;
	v->topl = v->m3;
	while (m->next != NULL)
	{
		while (m->y < 1 && m->x < (v->winx))
		{
			printf("next__rx:%d__ry:%d__", m->x, m->y);
			printf("__rx:%d__ry:%d__\n", m->next->x, m->next->y);
			ft_bsh(v, m, m->next);
			m = m->next;
		}
		if (m->x < v->winx)
			ft_bsh(v, m, m->next);
		ft_bsh(v, m, v->topl);
		v->topl = v->topl->next;
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
