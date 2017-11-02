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
	int				flag;
	int				width;
	int				modifier;
	int				length;
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
	fmt->flag = 0;
	fmt->width = 0;
	fmt->modifier = 0;
	fmt->length = 0;
	fmt->type = 0;
}

# define F_MINUS	0x01
# define F_PLUS		0x02
# define F_BLANK	0x04	
# define F_ZERO		0x08	
# define F_SHARP	0x10

void		set_formater(t_formater *fmt, const char *str, va_list *pa)
{
	/* activated flags */
	while(is_flag(*str))
	{
		if (*str == '-')
			fmt->flag |= F_MINUS;
		else if (*str == '+')
			fmt->flag |= F_PLUS;
		else if (*str == '#')
			fmt->flag |= F_SHARP;
		else if (*str == ' ')
			fmt->flag |= F_BLANK;
		else if (*str == '0')
			fmt->flag |= F_ZERO;
		if ((fmt->flag & F_MINUS) && (fmt->flag & F_ZERO))
			fmt->flag &= 0b10111; /* Ignor F_ZER0 */
		str++;
	}

	/* checking for asterik for width */
	if (*str == '*')
	{
		fmt->width = va_arg(*pa, int);
		printf("[DEBUG WIDTH] is: %d\n", fmt->width);
		str++;
	}
	else
	{
		char		*str_num;
		const char	*start;

		start = str;
		if (ft_isdigit(*str))
		{
			while (ft_isdigit(*str))
				str++;
			str_num = ft_strsub(start, 0, (size_t)(str - start));
			fmt->width = ft_atoi(str_num);
			printf("[DEBUG WIDTH] is: %d\n", fmt->width);
			free(str_num);
		}
	}

	/* checking precision */
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			fmt->length = va_arg(*pa, int);
			printf("[DEBUG PRECISION] is: %d\n", fmt->length);
			str++;
		}
		else
		{
			char		*str_num;
			const char	*start;

			start = str;
			if (ft_isdigit(*str))
			{
				while (ft_isdigit(*str))
					str++;
				str_num = ft_strsub(start, 0, (size_t)(str - start));
				fmt->length = ft_atoi(str_num);
				printf("[DEBUG PRECISION] is: %d\n", fmt->length);
				free(str_num);
			}
		}
	}
}
const char *fmt_specs(const char *str, va_list *pa)
{
	t_formater	fmt;

	init_formater(&fmt);
	str++;
	set_formater(&fmt, str, pa);
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
		if (*tmp != '%')
		{
			ft_putchar(*tmp);
			tmp++;
			continue ;
		}
		// go right and start format checking
		tmp = fmt_specs(tmp, &pa);
	}
	va_end(pa);

	return (2048);
}
