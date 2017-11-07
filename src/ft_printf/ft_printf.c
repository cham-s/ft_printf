/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:50:07 by cattouma          #+#    #+#             */
/*   Updated: 2017/11/07 02:34:09 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct	s_printf
{
	int			ret;
	const char	*str;
}				t_printf;

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

void		set_flags(t_formater *fmt, t_printf *pf)
{
	while(is_flag(*(pf->str)))
	{
		if (*(pf->str) == '-')
			fmt->flag |= F_MINUS;
		else if (*(pf->str) == '+')
			fmt->flag |= F_PLUS;
		else if (*(pf->str) == '#')
			fmt->flag |= F_SHARP;
		else if (*(pf->str) == ' ')
			fmt->flag |= F_BLANK;
		else if (*(pf->str) == '0')
			fmt->flag |= F_ZERO;
		if ((fmt->flag & F_MINUS) && (fmt->flag & F_ZERO))
			fmt->flag &= 0b10111; /* Ignore F_ZER0 */
		(pf->str)++;
	}
}

void		set_width(t_formater *fmt, t_printf *pf, va_list *pa)
{
	char		*str_num;
	const char	*start;

	if (*(pf->str) == '*')
	{
		fmt->width = va_arg(*pa, int);
		(pf->str)++;
	}
	else
	{
		start = pf->str;
		if (ft_isdigit(*(pf->str)))
		{
			while (ft_isdigit(*(pf->str)))
				(pf->str)++;
			str_num = ft_strsub(start, 0, (size_t)(pf->str - start));
			fmt->width = ft_atoi(str_num);
			free(str_num);
		}
	}
}

void		set_precision_length(t_formater *fmt, t_printf *pf, va_list *pa)
{
	char		*str_num;
	const char	*start;

	if (*(pf->str) == '.')
	{
		(pf->str)++;
		if (*(pf->str) == '*')
		{
			fmt->length = va_arg(*pa, int);
			(pf->str)++;
		}
		else
		{
			start = pf->str;
			if (ft_isdigit(*(pf->str)))
			{
				while (ft_isdigit(*(pf->str)))
					(pf->str)++;
				str_num = ft_strsub(start, 0, (size_t)(pf->str - start));
				fmt->length = ft_atoi(str_num);
				free(str_num);
			}
		}
	}
}

void	set_modifier(t_formater *fmt, t_printf *pf)
{
	if (is_modifier(*(pf->str)))
	{
		if (*(pf->str) == 'l' && *((pf->str) + 1) != 'l')
			fmt->modifier |= F_SL;
		else if (*(pf->str) == 'l' && *((pf->str) + 1) == 'l')
			fmt->modifier |= F_DL;
		else if (*(pf->str) == 'h' && *((pf->str) + 1) != 'h')
			fmt->modifier |= F_SH;
		else if (*(pf->str) == 'h' && *((pf->str) + 1) == 'h')
			fmt->modifier |= F_DH;
		else if (*(pf->str) == 'z')
			fmt->modifier |= F_Z;
		if ((fmt->modifier & F_DL) || fmt->modifier & F_DH)
			(pf->str)++;
		(pf->str)++;
	}
	if (is_modifier(*(pf->str)))
	{
		while (is_modifier(*(pf->str)))
			(pf->str)++;
	}
}

void		set_type(t_formater *fmt, t_printf *pf)
{
	if (is_type(*(pf->str)))
	{
		if (*(pf->str) == 's')
			fmt->type = T_S;
		else if (*(pf->str) == 'S')
			fmt->type = T_GS;
		else if (*(pf->str) == 'p')
			fmt->type = T_P;
		else if (*(pf->str) == 'd')
			fmt->type = T_D;
		else if (*(pf->str) == 'd')
			fmt->type = T_D;
		else if (*(pf->str) == 'D')
			fmt->type = T_GD;
		else if (*(pf->str) == 'i')
			fmt->type = T_I;
		else if (*(pf->str) == 'o')
			fmt->type = T_O;
		else if (*(pf->str) == 'O')
			fmt->type = T_GO;
		else if (*(pf->str) == 'u')
			fmt->type = T_U;
		else if (*(pf->str) == 'U')
			fmt->type = T_GU;
		else if (*(pf->str) == 'x')
			fmt->type = T_X;
		else if (*(pf->str) == 'X')
			fmt->type = T_GX;
		else if (*(pf->str) == 'c')
			fmt->type = T_C;
		else if (*(pf->str) == 'C')
			fmt->type = T_GC;
		(pf->str)++;
	}
}

void		set_formater(t_formater *fmt, t_printf *pf, va_list *pa)
{
	set_flags(fmt, pf);
	set_width(fmt, pf, pa);
	set_precision_length(fmt, pf, pa);
	set_modifier(fmt, pf);
	set_type(fmt, pf);
}


void		handle_format_string(t_printf *pf, va_list *pa)
{
	t_formater	fmt;

	init_formater(&fmt);
	(pf->str)++;
	set_formater(&fmt, pf, pa);
	if (fmt.type == T_S)
	{
		char	*str;
		str = va_arg(*pa, char *);
		if (!str)
		{
			ft_putstr("(null)");
			pf->ret += NULL_LEN;
		}
		else
		{
			ft_putstr(str);
			pf->ret += (int )ft_strlen(str);
		}
	}
	else if (fmt.type == T_D)
	{
		int		num;
		char	*str_num;

		num = va_arg(*pa, int);
		str_num = ft_itoa(num);
		ft_putstr(str_num);
		pf->ret += (int )ft_strlen(str_num);
		free(str_num);
	}
	else if (fmt.type == T_P)
	{
		void				*n;
		unsigned long long	addr;
		char				*output;
		char				*str;

		n = va_arg(*pa, void*);
		addr = (unsigned long long)n;
		output = ft_ltoa_base(addr, 16);
		str = output;
		while(*str)
		{
			*str = ft_tolower(*str);
			str++;
		}
		ft_putstr("0x");
		ft_putstr(output);
		pf->ret += (int )(ft_strlen(output) + 2);
		free(output);
	}
}

void	init_printf(t_printf *pf, const char *format)
{
	pf->ret = 0;
	pf->str = format;
}

int	ft_printf(const char *format, ...)
{
	va_list		pa;
	t_printf	pf;

	init_printf(&pf, format);
	if (!format)
	{
		ft_putstr("(null)");
		return (NULL_LEN);
	}
	va_start(pa, format);
	while (*(pf.str) != '\0')
	{
		if (*(pf.str) != '%')
		{
			ft_putchar(*(pf.str));
			pf.ret += 1;
			(pf.str)++;
			continue ;
		}
		handle_format_string(&pf, &pa);
	}
	va_end(pa);
	return (pf.ret);
}
