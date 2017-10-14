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

typedef struct		s_formater
{
	char			flags[3];
	char			*width[3];
	char			*precision[3];
	char			*length[3];
	char			*type[3];
}					t_formater;

/* char *fmt_specs(const char *str) */
/* { */
/* 	while */
/* } */

int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		ret;

	ret = 0;
	//const char *cur_arg = format;
	char **strs = ft_strsplit(format, '%');
	(void)strs;

	if (!format)
	{
		ft_putstr("(null)");
		return (NULL_LEN);
	}

	if (tabcontains(flags, '#'))
		ft_putendl("yes");
	else
		ft_putendl("no");
	exit(0);

	va_start(pa, format);
	va_end(pa);

	return (2048);

}
