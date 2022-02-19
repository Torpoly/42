/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:48:32 by rpol              #+#    #+#             */
/*   Updated: 2022/02/19 14:34:51 by rpol             ###   ########.fr       */
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

static int	ft_countpoints(char *s, t_vars *vars)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (ft_isdigit(s[0]))
		count++;
	while (s[i] != '\n')
	{
		while (ft_isdigit(s[i]))
			i++;
		if (s[i] == ' ')
			count++;
		while (s[i] == ' ')
			i++;
		if (s[i] != '-' && (!ft_isdigit(s[i])) && s[i] != '\n')
			return (vars->err = 1, 0);
		if (s[i] == '-' && !ft_isdigit(s[i + 1]))
			return (vars->err = 1, 0);
		if (s[i] == '-')
			i++;
	}
	return (count);
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
		return (free(s_read), NULL);
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
		return (free(s), NULL);
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

int	gnl(t_vars *vars)
{
	t_tab	*tab;

	tab = malloc(sizeof(t_tab));
	if (!tab)
		return (0);
	vars->tab = tab;
	while (1)
	{
		tab->s = get_next_line(vars->fd);
		if (vars->winy == 0)
		{
			vars->winx = ft_countpoints(tab->s, vars);
			tab->next = NULL;
		}
		if (tab->s == 0)
			break ;
		if (vars->winx != ft_countpoints(tab->s, vars))
			return (vars->err = 1, 0);
		tab->next = malloc(sizeof(t_tab));
		if (!tab->next)
			return (vars->err = 1, 0);
		vars->winy++;
		tab = tab->next;
	}
	return (close(vars->fd), tab->next = NULL, 1);
}
