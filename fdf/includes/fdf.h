/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:16:22 by rpol              #+#    #+#             */
/*   Updated: 2022/02/07 18:01:06 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "mlx.h"
# include "libft.h"


typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
    char    *name;
    int     fd;
    int     winx;
    int     winy;
    char    **tab;
    int     err;
    size_t  stdc;
    t_map   *map;
    t_map   *topl;
}				t_vars;

typedef struct	s_map {
	int	    x;
	int     y;
	int     z;
    char   *c;
    t_map   *next;
}				t_map;


/*IN FDF.C*/

int fput(char *s);

/*IN FT_PARSING.C*/

int	      ft_parsing(int ac, char **av, t_vars *vars);

/*IN GET_NEXT_LINE.C*/

char	*get_next_line(int fd);

char	**gnl(t_vars *vars);

/*IN GET_NEXT_LINE_UTILS.C*/

int		ft_strchr(char *s, char c);

int		ft_strlen(char *s);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_line(char *s);

char	*ft_cut(char *s, char *line);

/* ft_split_ps.c */

char			**ft_free_array(char **sa, int i);

char			**ft_split_ps(char *s, char c, int i);

#endif