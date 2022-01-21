/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:30:58 by rpol              #+#    #+#             */
/*   Updated: 2022/01/19 05:51:58 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_display_array(char **sa)
{
	int	i;

	i = -1;
	while (++i < ft_strlen_a(sa))
	{
		write(1, sa[i], ft_strlen(sa[i]));
		write(1, "\n", 1);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**sa;

	if (ac > 1)
	{
		sa = ft_parsing(ac, av);
		if (!sa)
			return (write(2, "Error\n", 6), -1);
		sa = ft_simplify(sa);
		if (!sa)
			return (write(2, "Error\n", 6), -1);
		ft_startsort(sa, ft_strlen_a(sa));
		return (ft_free_array(sa, ft_strlen_a(sa)), -1);
	}
	return (0);
}
