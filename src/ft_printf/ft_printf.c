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

void	output_str(t_info *i)
{
	t_str		*treg;
	t_str		*tspe;
	t_str_uni	*tspe_uni;

	treg = i->reg;
	tspe = i->spe;
	tspe_uni = i->spe_uni;
	while (treg || tspe || tspe_uni)
	{
		if (treg)
		{
			ft_putstr(treg->str);
			treg = treg->next;
		}
		if (tspe && tspe_uni)
		{
			if (tspe->pos < tspe_uni->pos)
			{
				ft_putstr(tspe->str);
				tspe = tspe->next;
			}
			else
			{
				ft_putstruni(tspe_uni->str);
				tspe_uni = tspe_uni->next;
			}
		}
		else
		{
			if (tspe)
			{
				ft_putstr(tspe->str);
				tspe = tspe->next;
			}
			if (tspe_uni)
			{
				ft_putstruni(tspe_uni->str);
				tspe_uni = tspe_uni->next;
			}
		}
	}
}

int	ft_printf(const char *format, ...)
{
	t_info	i;

	init_info(&i);
	va_start(i.args, format);

	while (*format)
	{
		if (!*(format = get_regular_str((char *)format, &i)))
			continue ;
		if (!*(format = get_special_str((char *)format, &i)))
			continue ;
	}
	va_end(i.args);
	output_str(&i);

	return (i.ret);
}

/* int	ft_printf(const char *format, ...) */
/* { */
/* 	va_list	pa; */
/* 	int		ret; */
/*  */
/* 	ret = 0; */
/* 	const char *cur_arg = format; */
/*  */
/* 	if (!format) */
/* 	{ */
/* 		ft_putstr("(null)"); */
/* 		return (NULL_LEN); */
/* 	} */
/*  */
/* 	va_start(pa, format); */
/*  */
/* 	while (*cur_arg) */
/* 	{ */
/* 		if (*cur_arg == '%') */
/* 		{ */
/* 			++cur_arg; */
/* 			else if (*cur_arg == 'D') */
/*  */
/*  */
/*  */
/*  */
/*  */
/* 			if (!*cur_arg) */
/* 				return (ret); */
/* 			if (*cur_arg == '%') */
/* 			{ */
/* 				ft_putchar(*cur_arg); */
/* 				++ret; */
/* 			} */
/* 			else if (*cur_arg == 'd' || *cur_arg == 'i') */
/* 				spec_d(pa, &ret); */
/* 			else if (*cur_arg == 'D') */
/* 				spec_g_d(pa, &ret); */
/* 			else if (*cur_arg == 's') */
/* 				spec_s(pa, &ret); */
/* 			else if (*cur_arg == 'c') */
/* 				spec_c(pa, &ret); */
/* 			else if (*cur_arg == 'p') */
/* 				spec_p(pa, &ret); */
/* 			else if (*cur_arg == 'o') */
/* 				spec_o(pa, &ret); */
/* 			else if (*cur_arg == 'O') */
/* 				spec_g_o(pa, &ret); */
/* 			else if (*cur_arg == 'u') */
/* 				spec_u(pa, &ret); */
/* 			else if (*cur_arg == 'U') */
/* 				spec_g_u(pa, &ret); */
/* 			else if (*cur_arg == 'x') */
/* 				spec_x(pa, &ret); */
/* 			else if (*cur_arg == 'X') */
/* 				spec_g_x(pa, &ret); */
/* 			else if (*cur_arg == 'C') */
/* 				spec_g_c(pa, &ret); */
/* 			else if (*cur_arg == 'S') */
/* 				spec_g_s(pa, &ret); */
/* 			else if (*cur_arg == ' ') */
/* 			{ */
/* 				++cur_arg; */
/* 				while (*cur_arg == ' ') */
/* 					++cur_arg; */
/* 				if (*cur_arg) */
/* 				{ */
/* 					ft_putchar(*cur_arg); */
/* 					++ret; */
/* 					++cur_arg; */
/* 				} */
/* 				continue ; */
/* 			} */
/* 			else */
/* 			{ */
/* 				ft_putchar(*cur_arg); */
/* 				++ret; */
/* 			} */
/* 			++cur_arg; */
/* 		} */
/* 		else */
/* 		{ */
/* 			ft_putchar(*cur_arg); */
/* 			++cur_arg; */
/* 			++ret; */
/* 		} */
/* 	} */
/* 	va_end(pa); */
/* 	return (ret); */
/* } */
