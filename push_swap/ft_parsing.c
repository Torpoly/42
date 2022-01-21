/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:45:01 by rpol              #+#    #+#             */
/*   Updated: 2022/01/12 04:22:18 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_double(char **sa)
{
	int	i;
	int	j;
	int	len;
	int	*nba;

	len = ft_strlen_a(sa);
	nba = malloc(sizeof(int) * len);
	if (!nba)
		return (ft_free_array(sa, len));
	i = -1;
	while (++i < len)
	{
		nba[i] = (int)ft_atoi(sa[i]);
		j = -1;
		while (++j < i)
			if (nba[j] == nba[i])
				return (free(nba), ft_free_array(sa, len));
	}
	return (free(nba), sa);
}

static	int	ft_digit(int ac, char **av)
{
	int		i;
	char	c;

	while (--ac)
	{
		i = -1;
		while (av[ac][++i])
		{
			c = av[ac][i];
			if ((c < '0' || c > '9') && (c != '-' && c != ' '))
				return (1);
		}
	}
	return (0);
}

char	**ft_parsing(int ac, char **av)
{
	char	**sa;
	char	*s;
	int		i;

	if (ft_digit(ac, av))
		return (NULL);
	s = malloc(sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '\0';
	i = 0;
	while (++i < ac)
	{
		if (!av[i])
			break ;
		s = ft_strjoin(s, av[i]);
		if (!s)
			return (NULL);
	}
	sa = ft_split_ps(s, ' ', i);
	if (!sa)
		return (NULL);
	return (ft_double(sa));
}
