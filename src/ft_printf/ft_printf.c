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

int is_modifier(char c)
{
	char	str[5];
	int		i;

	i = 0;
	ft_strcpy(str, "hljz");
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

/*
 * Flags
 * */
# define F_MINUS	0x01
# define F_PLUS		0x02
# define F_BLANK	0x04	
# define F_ZERO		0x08	
# define F_SHARP	0x10

/*
 * Modifiers 
 * */
# define F_SH		0x01
# define F_SL		0x02
# define F_DH		0x04	
# define F_DL		0x08	
# define F_Z		0x10	

/*
 * Types 
 * */
# define T_S		1
# define T_GS		2
# define T_D		3
# define T_GD		4
# define T_I		5
# define T_O		6
# define T_GO		7
# define T_U		8
# define T_GU		9
# define T_X		10
# define T_GX		11
# define T_C		12	
# define T_GC		13
# define T_EE		14
# define T_FF		15
# define T_GG		16
# define T_AA		17
# define T_N		18
# define T_P		19

/*
 * A format string is composed of:
 * [ flag ] - [ width ] - [ precision ] - [ modifier ] - type
 * set formater takes a potential string fmt and build a data structure
 * from it. 
 * */

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
			fmt->flag &= 0b10111; /* Ignore F_ZER0 */
		str++;
	}

	/* checking for asterik for width */
	if (*str == '*')
	{
		fmt->width = va_arg(*pa, int);
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
				free(str_num);
			}
		}
	}

	/* Get length modifier */
	if (is_modifier(*str))
	{
		if (*str == 'l' && *(str + 1) != 'l')
			fmt->modifier |= F_SL;
		else if (*str == 'l' && *(str + 1) == 'l')
			fmt->modifier |= F_DL;
		else if (*str == 'h' && *(str + 1) != 'h')
			fmt->modifier |= F_SH;
		else if (*str == 'h' && *(str + 1) == 'h')
			fmt->modifier |= F_DH;
		else if (*str == 'z')
			fmt->modifier |= F_Z;
		if ((fmt->modifier & F_DL) || fmt->modifier & F_DH)
			str++;
		str++;
	}
	if (is_modifier(*str))
	{
		while (is_modifier(*str))
			str++;
	}

	//	ft_strcpy(str, "sSpdDioOuUxXcCeEfFgGaAn");
	/* Extract type */
	if (is_type(*str))
	{
		if (*str == 's')
			fmt->type = T_S;
		else if (*str == 'S')
			fmt->type = T_GS;
		else if (*str == 'p')
			fmt->type = T_P;
		else if (*str == 'd')
			fmt->type = T_D;
		else if (*str == 'd')
			fmt->type = T_D;
		else if (*str == 'D')
			fmt->type = T_GD;
		else if (*str == 'i')
			fmt->type = T_I;
		else if (*str == 'o')
			fmt->type = T_O;
		else if (*str == 'O')
			fmt->type = T_GO;
		else if (*str == 'u')
			fmt->type = T_U;
		else if (*str == 'U')
			fmt->type = T_GU;
		else if (*str == 'x')
			fmt->type = T_X;
		else if (*str == 'X')
			fmt->type = T_GX;
		else if (*str == 'c')
			fmt->type = T_C;
		else if (*str == 'C')
			fmt->type = T_GC;
	}
	if (fmt->flag)
		printf("[DEBUG flag] The flag is: %#2.2x\n", fmt->flag);
	if (fmt->width)
		printf("[DEBUG width] The width is: %d\n", fmt->width);
	if (fmt->length)
		printf("[DEBUG length] The precision length is: %d\n", fmt->length);
	if (fmt->modifier)
		printf("[DEBUG modifier] The modifier is: %#2.2x\n", fmt->modifier);
	if (fmt->type)
		printf("[DEBUG type] The type is: %d\n", fmt->type);
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
