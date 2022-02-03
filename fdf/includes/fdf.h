/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:16:22 by rpol              #+#    #+#             */
/*   Updated: 2022/02/03 22:05:53 by rpol             ###   ########.fr       */
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



#endif