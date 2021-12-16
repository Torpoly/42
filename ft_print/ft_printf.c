/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:52:11 by rpol              #+#    #+#             */
/*   Updated: 2021/12/06 05:30:24 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[len])
		ft_putchar(s[len++]);
	return (len);
}

static int	dispatch(char command, va_list ap)
{
	if (command == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (command == 's')
		return (ft_putstr(va_arg(ap, const char *)));
	if (command == 'p')
		return (ft_putpoi(va_arg(ap, unsigned long long), "0123456789abcdef"));
	if (command == 'd' || command == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (command == 'u')
		return (ft_putnbrb(va_arg(ap, unsigned int), "0123456789"));
	if (command == 'x')
		return (ft_putnbrb(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (command == 'X')
		return (ft_putnbrb(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	return (ft_putchar(command));
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	size_t	len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			len += dispatch(s[++i], ap);
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
