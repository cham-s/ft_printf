/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:50:07 by cattouma          #+#    #+#             */
/*   Updated: 2017/11/14 21:33:16 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ftstring.h"
#include "ftstdio.h"
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list		pa;
	t_printf	pf;

	init_printf(&pf, format);
	if (!format)
		return (write(1, "(null)", 6));
	else if (!ft_strcmp(format, "%"))
		return (0);
	va_start(pa, format);
	while (*(pf.str) != '\0')
	{
		if (*(pf.str) != '%')
		{
			ft_putchar(*(pf.str));
			pf.ret += 1;
			(pf.str)++;
			continue ;
		}
		handle_format_string(&pf, &pa);
	}
	va_end(pa);
	return (pf.fmt_err < 0 ? - 1: pf.ret);
}
