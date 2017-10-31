/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:50:07 by cattouma          #+#    #+#             */
/*   Updated: 2017/10/31 17:39:00 by cattouma         ###   ########.fr       */
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

int	is_type(char c)
{
	char	str[24];
	int		i;

	i = 0;
	ft_strcpy(str, "sSpdDioOuUxXcCeEfFgGaAn");
	while (str[i])
	{
		if (str[i] == c)
		{
			/* printf debug */
			printf("[DEBUG TYPE] It's indeed a type the char is %c\n", c);
			return (1);
		}
		i += 1;
	}
	return (0);
}

const char *fmt_specs(const char *str)
{
	int i = 0;

	str++;
	while(!is_type(str[i]))
	{
		i += 1;
	}
	return (str + i);
}

int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		ret;

	ret = 0;

	if (!format)
	{
		ft_putstr("(null)");
		return (NULL_LEN);
	}

	int i = 0;
	va_start(pa, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			// go right and start format checking
			format = fmt_specs(format + i);
		}
		else
			ft_putchar(format[i]);
		i += 1;
	}
	va_end(pa);

	return (2048);
}
