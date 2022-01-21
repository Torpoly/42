/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:53:14 by rpol              #+#    #+#             */
/*   Updated: 2022/01/12 03:36:28 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free_array(char **sa, int i)
{
	while (i >= 0)
	{
		free(sa[i]);
		i--;
	}
	free(sa);
	return (NULL);
}

static int	check_n_of_words(const char *s, char sep)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static int	len_b_sep(char const *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

static int	ft_real_num(char *s)
{
	int				i;
	long long int	nb;

	if (!s)
		return (1);
	if (s[0] == '-')
		if (s[1] == '\0' || s[1] == '-')
			return (1);
	i = -1;
	while (s[++i])
		if (s[i] >= '0' && s[i] <= '9')
			if (s[i + 1] != '\0' && s[i + 1] == '-')
				return (1);
	nb = ft_atoi(s);
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	return (0);
}

char	**ft_split_ps(char *s1, char c, int i)
{
	char	**sa;
	char	*s;

	i = -1;
	if (!s1)
		return (NULL);
	s = s1;
	sa = malloc(sizeof(char *) * (check_n_of_words(s, c) + 1));
	if (!sa)
		return (free(s1), NULL);
	while (check_n_of_words(s, c))
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			sa[++i] = ft_substr(s, 0, len_b_sep(s, c));
			if (!sa[i] || ft_real_num(sa[i]))
				return (free(s1), ft_free_array(sa, i));
		}
		while (*s && *s != c)
			s++;
	}
	sa[++i] = NULL;
	return (free(s1), sa);
}
