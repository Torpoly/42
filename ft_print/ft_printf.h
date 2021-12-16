/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:52:07 by rpol              #+#    #+#             */
/*   Updated: 2021/12/06 05:26:39 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

/*IN FT_PRINTF.C*/

int	ft_putchar(char c);

int	ft_putstr(const char *s);

int	ft_printf(const char *s, ...);

/*IN FT_PUTNBR.C*/

int	ft_putnbr(int n);

int	ft_putnbrb(unsigned int n, char *base);

int	ft_putpoi(unsigned long long n, char *base);

#endif
