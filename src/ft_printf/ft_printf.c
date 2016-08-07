/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:50:07 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/07 02:59:57 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		ret;

	ret = 0;
	const char *cur_arg = format;

	if (!format)
	{
		ft_putstr("(null)");
		return (NULL_LEN);
	}

	va_start(pa, format);

	while (*cur_arg)
	{
		if (*cur_arg == '%')
		{
			++cur_arg;
			if (*cur_arg == '%')
				ft_putchar(*cur_arg);
			if (*cur_arg == 'd' || *cur_arg == 'i')
				spec_d(pa, &ret);
			if (*cur_arg == 's')
				spec_s(pa, &ret);
			if (*cur_arg == 'p')
				spec_p(pa, &ret);
			++cur_arg;
		}
		else
		{
			ft_putchar(*cur_arg);
			++cur_arg;
			++ret;
		}
	}
	va_end(pa);
	return (ret);
}
