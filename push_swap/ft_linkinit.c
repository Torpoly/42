/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:58:29 by rpol              #+#    #+#             */
/*   Updated: 2022/01/19 03:31:20 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlk(t_link *a)
{
	while (a != NULL)
	{
		printf("%d\n", a->x);
		a = a->next;
	}
}

void	ft_freelk(t_pos tmp)
{
	t_link	*a;

	while (tmp.bota != NULL)
	{
		a = tmp.bota;
		tmp.bota = tmp.bota->prev;
		free(a);
	}
}

static t_pos	ft_initstk(t_pos tmp, int i, char **sa)
{
	t_link	*a;

	a = malloc(sizeof(t_link));
	if (!a)
		return (write(1, "Error\n", 6), tmp);
	a->x = (int)ft_atoi(sa[i]);
	a->prev = NULL;
	tmp.topa = a;
	tmp.topb = NULL;
	tmp.botb = NULL;
	tmp.totlen = ft_strlen_a(sa);
	tmp.blen = 0;
	tmp.botchunk = 0;
	tmp.topchunk = 19;
	tmp.chunkincr = 20;
	return (tmp);
}

t_pos	ft_linkinit(char **sa, int i)
{
	t_pos	tmp;
	t_link	*a;

	tmp = ft_initstk(tmp, i, sa);
	a = tmp.topa;
	while (a != NULL)
	{
		tmp.bota = a;
		if (sa[++i])
		{
			a->next = malloc(sizeof(t_link));
			if (!a->next)
				return (write(1, "Error\n", 6), ft_freelk(tmp), tmp);
			a = a->next;
			a->prev = tmp.bota;
			a->x = (int)ft_atoi(sa[i]);
		}
		else
		{
			a->next = NULL;
			a = a->next;
		}
	}
	return (tmp);
}
