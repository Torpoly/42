/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:31:50 by rpol              #+#    #+#             */
/*   Updated: 2022/01/19 03:31:16 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include	<unistd.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<stdio.h>

typedef struct s_link
{
	int				x;
	struct s_link	*prev;
	struct s_link	*next;
}	t_link;

typedef struct s_pos
{
	t_link	*topa;
	t_link	*bota;
	int		totlen;
	t_link	*topb;
	t_link	*botb;
	int		blen;
	t_link	*tmpprev;
	t_link	*curr;
	t_link	*tmpnext;
	int		botchunk;
	int		topchunk;
	int		chunkincr;
	int		post;
	int		posb;
	int		maxx;
	int		tmpx;
}	t_pos;

/* ft_sort.c */

void			ft_sort(t_pos *tmp, int i);

/* ft_swap.c */

void			ft_s(t_pos *tmp, int n);

void			ft_r(t_pos *tmp, int n);

void			ft_rr(t_pos *tmp, int n);

void			ft_pa(t_pos *tmp, int n);

void			ft_pb(t_pos *tmp, int n);

/* ft_startsort.c */

int				ft_startsort(char **sa, int i);

/* ft_push_swap.c */
int				ft_display(char **sa);

/* ft_parsing.c */

char			**ft_parsing(int ac, char **av);

/* ft_simplify.c */

char			**ft_simplify(char **sa);

/* ft_linkinit.c */

void			ft_freelk(t_pos tmp);

void			ft_printlk(t_link *a);

t_pos			ft_linkinit(char **sa, int i);

/* utils3.c */
/* utils2.c */

char			*ft_itoa(int n);

char			*ft_strdup(char *s);

void			ft_printop(int n);

/* utils1.c */

long long int	ft_atoi(const char *s);

char			*ft_substr(char *s, int start, int len);

int				ft_strlen(char *s);

int				ft_strlen_a(char **sa);

char			*ft_strjoin(char *s1, char *s2);

/* ft_split_ps.c */

char			**ft_free_array(char **sa, int i);

char			**ft_split_ps(char *s, char c, int i);

#endif