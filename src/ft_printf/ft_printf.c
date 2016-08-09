/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:50:07 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/08 04:14:46 by cattouma         ###   ########.fr       */
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
			if (!*cur_arg)
				return (ret);
			if (*cur_arg == '%')
			{
				ft_putchar(*cur_arg);
				++ret;
			}
			else if (*cur_arg == 'd' || *cur_arg == 'i')
				spec_d(pa, &ret);
			else if (*cur_arg == 'D')
				spec_g_d(pa, &ret);
			else if (*cur_arg == 's')
				spec_s(pa, &ret);
			else if (*cur_arg == 'c')
				spec_c(pa, &ret);
			else if (*cur_arg == 'p')
				spec_p(pa, &ret);
			else if (*cur_arg == 'o')
				spec_o(pa, &ret);
			else if (*cur_arg == 'O')
				spec_g_o(pa, &ret);
			else if (*cur_arg == 'u')
				spec_u(pa, &ret);
			else if (*cur_arg == 'U')
				spec_g_u(pa, &ret);
			else if (*cur_arg == 'x')
				spec_x(pa, &ret);
			else if (*cur_arg == 'X')
				spec_g_x(pa, &ret);
			else if (*cur_arg == 'C')
				spec_g_c(pa, &ret);
			else if (*cur_arg == 'S')
				spec_g_s(pa, &ret);
			else if (*cur_arg == ' ')
			{
				++cur_arg;
				while (*cur_arg == ' ')
					++cur_arg;
				if (*cur_arg)
				{
					ft_putchar(*cur_arg);
					++ret;
					++cur_arg;
				}
				continue ;
			}
			else
			{
				ft_putchar(*cur_arg);
				++ret;
			}
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
