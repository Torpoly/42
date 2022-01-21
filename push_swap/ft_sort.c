/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 03:31:22 by rpol              #+#    #+#             */
/*   Updated: 2022/01/21 16:35:06 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_chunk(t_pos *tmp, int i)
{
	if (tmp->blen == 0)
	{
		if (i > 300)
		{
			tmp->topchunk = 44;
			tmp->chunkincr = 45;
		}
		tmp->maxx = i - 1;
	}
	if (tmp->blen > tmp->topchunk)
	{
		tmp->botchunk += tmp->chunkincr;
		tmp->topchunk += tmp->chunkincr;
	}
}

static void	ft_search(t_pos *tmp)
{
	t_link	*a;

	a = tmp->topa;
	tmp->post = 0;
	while (a->x > tmp->topchunk)
	{
		a = a->next;
		tmp->post++;
	}
	tmp->tmpx = a->x;
	a = tmp->bota;
	tmp->posb = 1;
	while (a->x > tmp->topchunk)
	{
		a = a->prev;
		tmp->posb++;
	}
	if (tmp->post <= tmp->posb || tmp->tmpx > a->x)
		tmp->posb = 0;
	else
		tmp->post = 0;
}

static void	ft_pull(t_pos *tmp, int n)
{
	while (tmp->post > 0)
	{
		if (tmp->post == 1 && tmp->blen > 1 && (tmp->blen + 1 < tmp->totlen)
			&& n == 0 && tmp->topa->x > tmp->topa->next->x
			&& tmp->topb->x < tmp->topb->next->x)
			ft_s(tmp, 3);
		else
			ft_r(tmp, 4 + n);
		tmp->post--;
	}
	while (tmp->posb > 0)
	{
		ft_rr(tmp, 7 + n);
		tmp->posb--;
	}
}

static void	ft_searchlast(t_pos *tmp)
{
	t_link	*b;

	b = tmp->topb;
	while (b->x != tmp->maxx)
	{
		b = b->next;
		tmp->post++;
	}
	b = tmp->botb;
	tmp->posb = 1;
	while (b->x != tmp->maxx)
	{
		b = b->prev;
		tmp->posb++;
	}
	if (tmp->post <= tmp->posb)
		tmp->posb = 0;
	else
		tmp->post = 0;
}

void	ft_sort(t_pos *tmp, int i)
{
	while (tmp->blen < tmp->totlen)
	{
		ft_chunk(tmp, i);
		ft_search(tmp);
		ft_pull(tmp, 0);
		ft_pb(tmp, 11);
	}
	while (tmp->blen > 0)
	{
		ft_searchlast(tmp);
		ft_pull(tmp, 1);
		ft_pa(tmp, 10);
		tmp->maxx--;
	}
}
