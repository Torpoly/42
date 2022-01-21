/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:06:40 by rpol              #+#    #+#             */
/*   Updated: 2022/01/21 15:20:14 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_three(t_pos *tmp, int i)
{
	if (tmp->topa->x == 1 + i && tmp->topa->next->x == 0 + i)
		ft_s(tmp, 1);
	else if (tmp->topa->x == 2 + i && tmp->topa->next->x == 1 + i)
	{
		ft_s(tmp, 1);
		ft_rr(tmp, 7);
	}
	else if (tmp->topa->x == 2 + i && tmp->topa->next->x == 0 + i)
		ft_r(tmp, 4);
	else if (tmp->topa->x == 0 + i && tmp->topa->next->x == 2 + i)
	{
		ft_s(tmp, 1);
		ft_r(tmp, 4);
	}
	else if (tmp->topa->x == 1 + i && tmp->topa->next->x == 2 + i)
		ft_rr(tmp, 7);
}

static void	ft_four(t_pos *tmp)
{
	while (tmp->topa->x != 3)
	{
		if (tmp->topa->next->x == 3)
			ft_s(tmp, 1);
		else
			ft_rr(tmp, 7);
	}
	ft_pb(tmp, 11);
	ft_three(tmp, 0);
	ft_pa(tmp, 10);
	ft_r(tmp, 4);
}

static void	ft_five(t_pos *tmp)
{
	while (tmp->topa->x != 0)
	{
		if (tmp->topa->next->x == 0 || tmp->topa->next->x == 0)
			ft_r(tmp, 4);
		else
			ft_rr(tmp, 7);
	}
	ft_pb(tmp, 11);
	while (tmp->topa->x != 4)
	{
		if (tmp->topa->next->x == 4)
			ft_s(tmp, 1);
		else
			ft_rr(tmp, 7);
	}
	ft_pb(tmp, 11);
	ft_three(tmp, 1);
	ft_pa(tmp, 10);
	ft_r(tmp, 4);
	ft_pa(tmp, 10);
}

static int	ft_sorted(t_link *a)
{
	while (a->next != NULL)
	{
		if (a->x > a->next->x)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_startsort(char **sa, int i)
{
	t_pos	tmp;

	tmp = ft_linkinit(sa, 0);
	if (!tmp.topa)
		return (0);
	if (!ft_sorted(tmp.topa))
		return (ft_freelk(tmp), 0);
	if (i == 2)
	{
		if (tmp.topa->x == 1)
			write(1, "sa\n", 3);
	}
	else if (i == 3)
		ft_three(&tmp, 0);
	else if (i == 4)
		ft_four(&tmp);
	else if (i == 5)
		ft_five(&tmp);
	else if (i > 5)
		ft_sort(&tmp, i);
	return (ft_freelk(tmp), 0);
}
