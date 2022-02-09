/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:48:32 by rpol              #+#    #+#             */
/*   Updated: 2022/02/07 16:07:31 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_shorten(char *s1, char *s2, int i)
{
	if (i == 1)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	if (i == 2)
	{
		if (!s1)
		{
			s1 = malloc(sizeof(char));
			if (!s1)
				return (NULL);
			else
				s1[0] = '\0';
		}
		return (s1);
	}
	return (NULL);
}

static char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

static char	*ft_read(int fd, char *s)
{
	char	*s_read;
	int		i;

	i = 1;
	s_read = malloc(sizeof(char) * (100 + 1));
	if (!s_read)
		return (NULL);
	s = ft_shorten(s, s_read, 2);
	if (!s)
		return (ft_free(s_read));
	while (i > 0 && ft_strchr(s, '\n'))
	{
		i = read(fd, s_read, 100);
		if (i < 0)
			return (ft_shorten(s, s_read, 1));
		s_read[i] = '\0';
		s = ft_strjoin(s, s_read);
		if (!s)
			return (ft_shorten(s, s_read, 1));
	}
	free(s_read);
	if (s[0] == '\0')
		return (ft_free(s));
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0)
		return (0);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	line = ft_line(s);
	s = ft_cut(s, line);
	return (line);
}

char	**gnl(t_vars *vars)
{
	char	**tab;

	while (1)
	{
		tab[vars->winy] = get_next_line(vars->fd);
		if (tab[vars->winy] == 0)
			break ;
		vars->winy++;
	}
	close(vars->fd);
	return (tab);
}
