/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:48:32 by rpol              #+#    #+#             */
/*   Updated: 2022/01/08 05:01:52 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	s_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s_read)
		return (NULL);
	s = ft_shorten(s, s_read, 2);
	if (!s)
		return (ft_free(s_read));
	while (i > 0 && ft_strchr(s, '\n'))
	{
		i = read(fd, s_read, BUFFER_SIZE);
		if (i < 0)
			return (ft_shorten(s, s_read, 1));
		s_read[i] = '\0';
		s = ft_strjoin(s, s_read);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	line = ft_line(s);
	s = ft_cut(s, line);
	return (line);
}

/*int	main(void)
{	
	int		fd;
	char	*str;
	int		i;

	i=5;
	fd = open("test.txt", O_RDONLY);
	while (i>0)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
		i--;
	}
}*/
