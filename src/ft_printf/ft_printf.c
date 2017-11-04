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
	debug_fmt(fmt);
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
