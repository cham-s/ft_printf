/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 23:14:37 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/07 03:00:46 by cattouma         ###   ########.fr       */
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
