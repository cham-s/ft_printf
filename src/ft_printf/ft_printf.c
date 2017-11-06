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

void	debug_fmt(t_formater *fmt)
{
	if (fmt->flag)
	{
		printf("[DEBUG flag] The flag is: ");
		if (fmt->flag & F_MINUS)
			printf("- ");
		if (fmt->flag & F_PLUS)
			printf("+ ");
		if (fmt->flag & F_BLANK)
			printf("blank ");
		if (fmt->flag & F_ZERO)
			printf("0 ");
		if (fmt->flag & F_SHARP)
			printf("# ");
		printf("\n");
	}
	if (fmt->width)
		printf("[DEBUG width] The width is: %d\n", fmt->width);
	if (fmt->length)
		printf("[DEBUG length] The precision length is: %d\n", fmt->length);
	if (fmt->modifier)
	{
		printf("[DEBUG modifier] The modifier is: ");
		if (fmt->modifier & F_SH)
			printf("h ");
		if (fmt->modifier & F_SL)
			printf("l ");
		if (fmt->modifier & F_DL)
			printf("ll ");
		if (fmt->modifier & F_DH)
			printf("hh ");
		if (fmt->modifier & F_Z)
			printf("z ");
		printf("\n");
	}
	if (fmt->type)
	{
		printf("[DEBUG type] The type is: ");
		if (fmt->type == T_S)
			printf("s");
		else if (fmt->type == T_GS)
			printf("S");
		else if (fmt->type == T_GS)
			printf("S");
		else if (fmt->type == T_D)
			printf("d");
		else if (fmt->type == T_GD)
			printf("GD");
		else if (fmt->type == T_I)
			printf("i");
		else if (fmt->type == T_O)
			printf("o");
		else if (fmt->type == T_GO)
			printf("O");
		else if (fmt->type == T_U)
			printf("u");
		else if (fmt->type == T_GU)
			printf("U");
		else if (fmt->type == T_X)
			printf("x");
		else if (fmt->type == T_GX)
			printf("X");
		else if (fmt->type == T_C)
			printf("c");
		else if (fmt->type == T_GC)
			printf("C");
		else if (fmt->type == T_EE)
			printf("eE");
		else if (fmt->type == T_FF)
			printf("fF");
		else if (fmt->type == T_GG)
			printf("gG");
		else if (fmt->type == T_AA)
			printf("aA");
		else if (fmt->type == T_N)
			printf("n");
		else if (fmt->type == T_P)
			printf("p");
		printf("\n");
	}
}

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

const char	*set_flags(t_formater *fmt, const char *str)
{
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
	return (str);
}

const char	*set_width(t_formater *fmt, const char *str, va_list *pa)
{
	char		*str_num;
	const char	*start;

	if (*str == '*')
	{
		fmt->width = va_arg(*pa, int);
		str++;
	}
	else
	{
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
	return (str);
}

const char	*set_precision_length(t_formater *fmt, const char *str, va_list *pa)
{
	char		*str_num;
	const char	*start;

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
	return (str);
}

const char	*set_modifier(t_formater *fmt, const char *str)
{
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
	return (str);
}

const char	*set_type(t_formater *fmt, const char *str)
{
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
	return (str);
}

void		set_formater(t_formater *fmt, const char *str, va_list *pa)
{
	str = set_flags(fmt, str);
	str = set_width(fmt, str, pa);
	str = set_precision_length(fmt, str, pa);
	str = set_modifier(fmt, str);
	str = set_type(fmt, str);
	debug_fmt(fmt);
}

const char *handle_format_string(const char *str, va_list *pa)
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
	const char	*str;

	ret = 0;
	str = format;
	if (!format)
	{
		ft_putstr("(null)");
		return (NULL_LEN);
	}
	va_start(pa, format);
	while (*str != '\0')
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			str++;
			continue ;
		}
		str = handle_format_string(str, &pa);
	}
	va_end(pa);
	return (2048);
}
