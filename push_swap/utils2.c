/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:37:52 by rpol              #+#    #+#             */
/*   Updated: 2022/01/18 05:37:55 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	sign(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	int		len;
	int		tmp;
	char	*s;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = intlen(n) + sign(&n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len--] = '\0';
	while (n > 0)
	{
		s[len--] = '0' + (n % 10);
		n /= 10;
	}
	if (tmp < 0)
		s[0] = '-';
	return (s);
}

char	*ft_strdup(char *s)
{
	int			i;
	char		*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!cpy)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	ft_printop(int n)
{
	if (n == 1)
		write(1, "sa\n", 3);
	else if (n == 2)
		write(1, "sb\n", 3);
	else if (n == 3)
		write(1, "ss\n", 3);
	else if (n == 4)
		write(1, "ra\n", 3);
	else if (n == 5)
		write(1, "rb\n", 3);
	else if (n == 6)
		write(1, "rr\n", 3);
	else if (n == 7)
		write(1, "rra\n", 4);
	else if (n == 8)
		write(1, "rrb\n", 4);
	else if (n == 9)
		write(1, "rrr\n", 5);
	else if (n == 10)
		write(1, "pa\n", 3);
	else if (n == 11)
		write(1, "pb\n", 3);
}
