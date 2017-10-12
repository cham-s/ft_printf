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

char *types[] = {"d", "i", "u", "o", "x", "X",
				 "f", "F", "e", "E", "g", "G",
				 "c", "s", "n", "p", "C", "S", NULL};

char *args_size[] = {"h", "l", "ll", "L", "H", "D", "DD", NULL};

char *flags[] = {"-", "+", " ", "#", "0", NULL};

int	fmt_tabsize(const char *str)
{
	while (*str)
	{
		str = ft_strchr(str, '%');
		ft_putstr(str);
		int i = 0;
		while (types[i++])
			ft_putendl(types[i]);
		exit(0);
	}
	return (2048);
}

/* char **fmt_specs(const char *str) */
/* { */
/* 	char **ret; */
/* } */

int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		ret;

	ret = 0;
	//const char *cur_arg = format;
	//fmt_tabsize(format);
	char **strs = ft_strsplit(format, '%');
	(void)strs;

	if (!format)
	{
		ft_putstr("(null)");
		return (NULL_LEN);
	}

	va_start(pa, format);
	va_end(pa);

	return (2048);

}
