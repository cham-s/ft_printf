/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 23:14:37 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/08 04:14:13 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_d(va_list pa, int *ret)
{
	int n;

	n = va_arg(pa, int);
	ft_putnbr(n);
	*ret += ft_strlen(ft_itoa(n));
}

void	spec_g_d(va_list pa, int *ret)
{
	long n;

	n = va_arg(pa, long);
	ft_putnbr(n);
	*ret += ft_strlen(ft_ltoa(n));
}

void	spec_c(va_list pa, int *ret)
{
	int c;

	c = va_arg(pa, int);
	ft_putchar(c);
	*ret += 1;
}

void	spec_s(va_list pa, int *ret)
{
	char *s;

	s = va_arg(pa, char*);
	if (!s)
	{
		ft_putstr("(null)");
		*ret += NULL_LEN;
		return ;
	}
	ft_putstr(s);
	*ret += ft_strlen(s);
}

void	spec_p(va_list pa, int *ret)
{
	void				*n;
	unsigned long long	addr;
	char				*output;
	char				*s;

	n = va_arg(pa, void*);
	addr = (unsigned long long)n;
	output = ft_ltoa_base(addr, 16);
	s = output;
	while (*s)
	{
		*s = ft_tolower(*s);
		s++;
	}
	ft_putstr("0x");
	ft_putstr(output);
	*ret += ft_strlen(output) + 2;
}
