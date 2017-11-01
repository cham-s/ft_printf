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

typedef struct		s_flag
{
	int	id;
	size_t			width;
}					t_flag;

typedef struct		s_precision
{
	int		modifier;
	size_t	length;
}					t_precision;

typedef struct		s_formater
{
	t_flag			flag;
	t_precision		precision;
	int				type;
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
			return (1);
		i += 1;
	}
	return (0);
}

int	is_flag(char c)
{
	char	str[6];
	int		i;

	i = 0;
	ft_strcpy(str, "+- #0");
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i += 1;
	}
	return (0);
}

void		init_formater(t_formater *fmt)
{
	fmt->flag.id = 0;
	fmt->flag.width = 0;
	fmt->precision.modifier = 0;
	fmt->precision.length = 0;
	fmt->type = 0;
}

# define F_MINUS	0b00001
# define F_PLUS	0b00010
# define F_BLANK	0b00100
# define F_ZERO	0b01000
# define F_SHARP	0b10000

void		set_formater(t_formater *fmt, const char *str)
{
		while(is_flag(*str))
		{
			if (*str == '-')
				fmt->flag.id |= F_MINUS;
			else if (*str == '+')
				fmt->flag.id |= F_PLUS;
			else if (*str == '#')
				fmt->flag.id |= F_ZERO;
			else if (*str == ' ')
				fmt->flag.id |= F_SHARP;
			else if (*str == '0')
				fmt->flag.id |= F_PLUS;
			str++;
		}
		printf("[ DEBUG Flag ] activated flags are: ");
		if (fmt->flag.id & F_MINUS)
			printf("- ");
		if (fmt->flag.id & F_PLUS)
			printf("+ ");
		if (fmt->flag.id & F_SHARP)
			printf("# ");
		if (fmt->flag.id & F_ZERO)
			printf("0 ");
		printf("\n");
}
const char *fmt_specs(const char *str)
{
	t_formater	fmt;

	init_formater(&fmt);
	str++;
	set_formater(&fmt, str);
	return (str);
}

int	ft_printf(const char *format, ...)
{
	va_list		pa;
	int			ret;
	const char	*tmp;

	ret = 0;
	tmp = format;

	if (!format)
	{
		ft_putstr("(null)");
		return (NULL_LEN);
	}

	va_start(pa, format);
	while (*tmp != '\0')
	{
		if (*tmp == '%')
		{
			// go right and start format checking
			tmp = fmt_specs(tmp);
		}
		else
			ft_putchar(*tmp);
		tmp++;
	}
	va_end(pa);

	return (2048);
}
