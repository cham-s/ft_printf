/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:50:07 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/06 03:07:29 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		ret;

	ret = 0;
	const char *cur_arg = format;

	if (format == NULL)
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
			//int vint = va_arg(pa, int);
			char *v_str = va_arg(pa, char*);
			//if (*cur_arg == 'd')
				//spec_d(&vint, &ret);
			if (*cur_arg == 's')
			{
				ft_putstr(v_str);
				exit(3);
				spec_s(v_str, &ret);
			}
			++cur_arg;
		}
		ft_putchar(*cur_arg);
		++cur_arg;
		++ret;
	}
	va_end(pa);
	return (ret);
}
