/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:14:06 by rpol              #+#    #+#             */
/*   Updated: 2021/12/06 05:22:35 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nlen(int n)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = nlen(n);
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n = n % 10 ;
		ft_putchar(n + '0');
	}
	else
		ft_putchar(n + '0');
	return (len);
}

int	ft_putnbrb(unsigned int n, char *base)
{
	int	len_base;
	int	*n_final;
	int	i;

	i = 0;
	len_base = 0;
	if (n == 0)
		return (ft_putchar('0'));
	n_final = malloc(sizeof(int) * 10);
	if (!n_final)
		return (0);
	while (base[len_base])
		len_base++;
	while (n)
	{
		n_final[i++] = n % len_base;
		n /= len_base;
	}
	len_base = i;
	while (--i >= 0)
		ft_putchar(base[n_final[i]]);
	free(n_final);
	return (len_base);
}

int	ft_putpoi(unsigned long long n, char *base)
{
	int	len_base;
	int	*n_final;
	int	i;

	i = 0;
	len_base = 0;
	ft_putstr("0x");
	if (n == 0)
		return (2 + ft_putchar('0'));
	n_final = malloc(sizeof(int) * 20);
	if (!n_final)
		return (0);
	while (base[len_base])
		len_base++;
	while (n)
	{
		n_final[i++] = n % len_base;
		n /= len_base;
	}
	len_base = i;
	while (--i >= 0)
		ft_putchar(base[n_final[i]]);
	free(n_final);
	return (len_base + 2);
}
