/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:31:17 by rpol              #+#    #+#             */
/*   Updated: 2022/01/12 03:04:09 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi(const char *s)
{
	long long int	i;
	int				sign;
	long long int	nb;

	sign = 1;
	i = 0;
	nb = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '-')
		sign = -1;
	if (sign == -1 || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = (nb * 10) + (s[i] - '0');
		i++;
	}
	return (nb * sign);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		lens;
	char	*news;

	i = 0;
	lens = ft_strlen(s);
	if (start >= lens)
		return (NULL);
	if (len > lens - start)
		len = lens - start;
	news = malloc(sizeof(char) * (len + 1));
	if (!news)
		return (NULL);
	while (i < len)
	{
		news[i] = s[start + i];
		i++;
	}
	news[i] = '\0';
	return (news);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_a(char **sa)
{
	int	i;

	if (!sa)
		return (0);
	i = 0;
	while (sa[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*news;

	i = 0;
	if (!s2)
		return (free(s1), NULL);
	news = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!news)
		return (free(s1), NULL);
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i < ft_strlen(s1))
			news[i] = s1[i];
		else
			news[i] = s2[(i - ft_strlen(s1))];
		i++;
	}
	news[i++] = ' ';
	news[i] = '\0';
	return (free(s1), news);
}
