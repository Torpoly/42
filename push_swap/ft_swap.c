/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:41:50 by rpol              #+#    #+#             */
/*   Updated: 2022/01/19 04:59:40 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_pos *tmp, int n)
{
	if (n == 1 || n == 3)
	{
		tmp->tmpx = tmp->topa->x;
		tmp->topa->x = tmp->topa->next->x;
		tmp->topa->next->x = tmp->tmpx;
	}
	if (n == 2 || n == 3)
	{
		tmp->tmpx = tmp->topb->x;
		tmp->topb->x = tmp->topb->next->x;
		tmp->topb->next->x = tmp->tmpx;
	}
	ft_printop(n);
}

void	ft_r(t_pos *tmp, int n)
{
	if (n == 4 || n == 6)
	{
		tmp->topa = tmp->topa->next;
		tmp->bota->next = tmp->topa->prev;
		tmp->bota->next->prev = tmp->bota;
		tmp->bota = tmp->bota->next;
		tmp->bota->next = NULL;
		tmp->topa->prev = NULL;
	}
	if (n == 5 || n == 6)
	{
		tmp->topb = tmp->topb->next;
		tmp->botb->next = tmp->topb->prev;
		tmp->botb->next->prev = tmp->botb;
		tmp->botb = tmp->botb->next;
		tmp->botb->next = NULL;
		tmp->topb->prev = NULL;
	}
	ft_printop(n);
}

void	ft_rr(t_pos *tmp, int n)
{
	if (n == 7 || n == 9)
	{
		tmp->bota = tmp->bota->prev;
		tmp->bota->next->next = tmp->topa;
		tmp->topa->prev = tmp->bota->next;
		tmp->topa = tmp->topa->prev;
		tmp->bota->next = NULL;
		tmp->topa->prev = NULL;
	}
	if (n == 8 || n == 9)
	{
		tmp->botb = tmp->botb->prev;
		tmp->botb->next->next = tmp->topb;
		tmp->topb->prev = tmp->botb->next;
		tmp->topb = tmp->topb->prev;
		tmp->botb->next = NULL;
		tmp->topb->prev = NULL;
	}
	ft_printop(n);
}

void	ft_pb(t_pos *tmp, int n)
{
	if (tmp->blen == 0)
	{
		tmp->topb = tmp->topa;
		tmp->botb = tmp->topa;
		tmp->topa = tmp->topa->next;
		tmp->topa->prev = NULL;
		tmp->botb->next = NULL;
	}
	else
	{
		tmp->topb->prev = tmp->topa;
		tmp->topa = tmp->topa->next;
		tmp->topb->prev->next = tmp->topb;
		tmp->topb = tmp->topb->prev;
		if (tmp->totlen - tmp->blen > 1)
			tmp->topa->prev = NULL;
	}
	tmp->blen += 1;
	ft_printop(n);
}

void	ft_pa(t_pos *tmp, int n)
{
	if (tmp->totlen - tmp->blen == 0)
	{
		tmp->topa = tmp->topb;
		tmp->bota = tmp->topb;
		tmp->topb = tmp->topb->next;
		tmp->topb->prev = NULL;
		tmp->bota->next = NULL;
	}
	else
	{
		tmp->topa->prev = tmp->topb;
		tmp->topb = tmp->topb->next;
		tmp->topa->prev->next = tmp->topa;
		tmp->topa = tmp->topa->prev;
		if (tmp->blen > 1)
			tmp->topb->prev = NULL;
	}
	tmp->blen -= 1;
	ft_printop(n);
}
