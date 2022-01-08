/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:50:21 by rpol              #+#    #+#             */
/*   Updated: 2022/01/08 01:48:15 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

/*IN GET_NEXT_LINE.C*/

char	*get_next_line(int fd);

/*IN GET_NEXT_LINE_UTILS.C*/

int		ft_strchr(char *s, char c);

int		ft_strlen(char *s);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_line(char *s);

char	*ft_cut(char *s, char *line);

#endif
