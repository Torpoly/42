/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:35:40 by rpol              #+#    #+#             */
/*   Updated: 2022/01/12 23:49:35 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*b_sorting(int *nba, int len, int swap)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	swap = 1;
	while (++i < len && swap != 0)
	{
		j = -1;
		swap = 0;
		while (++j < len - i -1)
		{
			if (nba[j] > nba[j + 1])
			{
				tmp = nba[j];
				nba[j] = nba[j + 1];
				nba[j + 1] = tmp;
				swap++;
			}
		}
	}
	return (nba);
}

static char	**ft_makeindex(char **sa, int *nba, int len)
{
	char	**index;
	int		i;
	int		j;

	index = malloc(sizeof(char *) * (len + 1));
	if (!index)
		return (free(nba), ft_free_array(sa, ft_strlen_a(sa)));
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (nba[i] == ft_atoi(sa[j]))
			{
				index[j] = ft_itoa(i);
				if (!index[j])
					return (ft_free_array(sa, len), ft_free_array(index, len));
			}
		}
	}
	index[i] = NULL;
	return (ft_free_array(sa, len), index);
}

char	**ft_simplify(char **sa)
{
	int		i;
	int		len;
	int		*nba;
	char	**index;

	len = ft_strlen_a(sa);
	nba = malloc(sizeof(int) * len);
	if (!nba)
		return (ft_free_array(sa, ft_strlen_a(sa)));
	i = -1;
	while (++i < len)
		nba[i] = (int)ft_atoi(sa[i]);
	nba = b_sorting(nba, len, i);
	index = ft_makeindex(sa, nba, len);
	if (!index)
		return (free(nba), NULL);
	return (free(nba), index);
}
