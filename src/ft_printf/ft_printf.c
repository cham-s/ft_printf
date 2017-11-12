/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:50:07 by cattouma          #+#    #+#             */
/*   Updated: 2017/11/11 19:27:03 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct	s_printf
{
	int			ret;
	const char	*str;
	char		*fmt_str;
	size_t		len_str;
}				t_printf;

int				print_padding(t_formater *fmt, int size)
{
	int ret;

	ret = 0;
	while (size--)
	{
		if (fmt->flag & F_ZERO)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ret += 1;
	}
	return (ret);
}

void			print_flag_width(t_formater *fmt, t_printf *pf)
{
	int		size;
	int		is_neg;

	is_neg = pf->fmt_str[0] == '-' ? 1 : 0;
	if (fmt->flag & F_BLANK && fmt->width == 0)
	{
		ft_putchar(' ');
		pf->ret += 1;
	}
	size = fmt->width - pf->len_str;
	size = size < 0 ? 0 : size;
	if(!(fmt->flag & F_MINUS))
	{
		if (fmt->flag & F_ZERO && is_neg)
			ft_putchar('-');
		pf->ret += print_padding(fmt, size);
		ft_putstr(fmt->flag & F_ZERO && is_neg? pf->fmt_str + 1 : pf->fmt_str);
	}
	else
	{
		ft_putstr(pf->fmt_str);
		pf->ret += print_padding(fmt, size);
	}
}

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
	char	str[25];
	int		i;

	i = 0;
	ft_strcpy(str, "%sSpdDioOuUxXcCeEfFgGaAn");
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
		else if (*(pf->str) == '%')
			fmt->type = T_PNT;
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
	if (fmt.type == T_PNT)
	{
		ft_putchar('%');
		pf->ret += 1;
	}
	else if (fmt.type == T_S)
	{
		unsigned int *str;

		str = NULL;
		str = va_arg(*pa, unsigned int*);
		if (!str)
		{
			ft_putstr("(null)");
			pf->ret += NULL_LEN;
		}
		else
		{
			if (fmt.modifier & F_SL)
				pf->ret += ft_putstruni(str);
			else
			{
				ft_putstr((char *)str);
				pf->ret += (int )ft_strlen((const char *)str);
			}
		}
	}
	else if (fmt.type == T_D || fmt.type == T_I)
	{
		long long int	num;
		int				more;

		more = 0;
		num = va_arg(*pa, long long);
		if (fmt.modifier & F_SL)
			pf->fmt_str = ft_ltoa_base((long int ) num, 10);
		else if (fmt.modifier & F_DL)
			pf->fmt_str = ft_ltoa_base(num, 10);
		else if (fmt.modifier & F_SH)
			pf->fmt_str = ft_stoa_base((short )num, 10);
		else if (fmt.modifier & F_DH)
			pf->fmt_str = ft_ctoa_base((char )num, 10);
		else if (fmt.modifier & F_Z)
			pf->fmt_str = ft_ltoa_base(num, 10);
		else
			pf->fmt_str = ft_itoa_base((int )num, 10);
		if (fmt.flag & F_PLUS)
		{
			if (pf->fmt_str[0] != '-')
			{
				ft_putchar('+');
				more += 1;
			}
		}
		pf->len_str = ft_strlen(pf->fmt_str) + more;
		print_flag_width(&fmt, pf);
		pf->ret += (int )pf->len_str;
		free(pf->fmt_str);
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
		pf->fmt_str = output;
		pf->len_str = (ft_strlen(output) + 2);
		print_flag_width(&fmt, pf);
		pf->ret += (int )pf->len_str;
		free(output);
	}
	else if (fmt.type == T_C)
	{
		if (fmt.modifier & F_SL)
			pf->ret += ft_putunicode(va_arg(*pa, unsigned int));
		else
		{
			ft_putchar(va_arg(*pa, int));
			pf->ret += 1;
		}
	/* 	int	size; */
    /*  */
	/* 	size = fmt.width - 1; */
	/* 	if(!(fmt.flag & F_MINUS)) */
	/* 		pf->ret += print_padding(&fmt, size); */
	/* 	if (fmt.modifier & F_SL) */
	/* 		pf->ret += ft_putunicode(va_arg(*pa, unsigned int)); */
	/* 	else */
	/* 	{ */
	/* 		ft_putchar(va_arg(*pa, int)); */
	/* 		pf->ret += 1; */
	/* 	} */
	/* 	if(fmt.flag & F_MINUS) */
	/* 		pf->ret += print_padding(&fmt, size); */
	/* } */
	/* else if (fmt.type == T_GC) */
	/* { */
	/* 	unsigned int ch; */
    /*  */
	/* 	ch = va_arg(*pa, unsigned int); */
	/* 	pf->ret += ft_putunicode(ch); */
	/* } */
	}
	else if (fmt.type == T_GC)
	{
		unsigned int ch;

		ch = va_arg(*pa, unsigned int);
		pf->ret += ft_putunicode(ch);
	}
	else if (fmt.type == T_GS)
	{
		unsigned int *str;

		str = va_arg(*pa, unsigned int *);
		if (!str)
		{
			ft_putstr("(null)");
			pf->ret += NULL_LEN;
		}
		else
			pf->ret += ft_putstruni(str);
	}
	else if (fmt.type == T_GD)
	{
		long long n;

		n = va_arg(*pa, long long);
		ft_putnbr(n);
		pf->ret += ft_strlen(ft_ltoa_base(n, 10));
	}
	else if (fmt.type == T_O)
	{
		char	*s;
		int		more;

		more = 0;
		if (fmt.modifier & F_DH)
			s = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 8);
		else if (fmt.modifier & F_SH)
			s = ft_ustoa_base((unsigned short)va_arg(*pa, unsigned int), 8);
		else if (fmt.modifier & F_SL)
			s = ft_ultoa_base(va_arg(*pa, unsigned long), 8);
		else if (fmt.modifier & F_DL)
			s = ft_ultoa_base(va_arg(*pa, unsigned long long), 8);
		else if (fmt.modifier & F_Z)
			s = ft_ultoa_base(va_arg(*pa, size_t), 8);
		else
			s = ft_uitoa_base(va_arg(*pa, unsigned int), 8);
		if (fmt.flag & F_SHARP && s[0] != '0')
		{
			ft_putstr("0");
			more += 1;
		}
		pf->len_str = ft_strlen(s) + more;
		pf->fmt_str = s;
		print_flag_width(&fmt, pf);
		pf->ret += pf->len_str;
		free(s);
	}
	else if (fmt.type == T_GO)
	{
		char	*s;
		int		more;

		more = 0;
		s = ft_ltoa_base(va_arg(*pa, unsigned long), 8);
		if (fmt.flag & F_SHARP)
		{
			ft_putstr("0");
			more += 1;
		}
		pf->len_str = ft_strlen(s) + more;
		pf->fmt_str = s;
		print_flag_width(&fmt, pf);
		pf->ret += pf->len_str;
		free(s);
	}
	else if (fmt.type == T_X)
	{
		char	*s;
		char	*output;
		int		more;

		more = 0;
		if (fmt.modifier & F_DH)
			output = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 16);
		else if (fmt.modifier & F_SH)
			output = ft_ustoa_base((unsigned short)va_arg(*pa, unsigned int), 16);
		else if (fmt.modifier & F_SL)
			output = ft_ultoa_base(va_arg(*pa, unsigned long), 16);
		else if (fmt.modifier & F_DL)
			output = ft_ultoa_base(va_arg(*pa, unsigned long long), 16);
		else
			output = ft_ultoa_base(va_arg(*pa, size_t), 16);
		s = output;
		while (*s)
		{
			*s = ft_tolower(*s);
			s++;
		}
		if (fmt.flag & F_SHARP && output[0] != '0')
		{
			ft_putstr("0x");
			more += 2;
		}
		pf->len_str = ft_strlen(output) + more;
		pf->fmt_str = output;
		print_flag_width(&fmt, pf);
		pf->ret += pf->len_str;
		free(output);
	}
	else if (fmt.type == T_GX)
	{
		char	*output;
		int		more;

		more = 0;
		output = NULL;
		if (fmt.modifier & F_DH)
			output = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 16);
		else if (fmt.modifier & F_SH)
			output = ft_ustoa_base((unsigned short)va_arg(*pa, unsigned int), 16);
		else if (fmt.modifier & F_SL)
			output = ft_ultoa_base(va_arg(*pa, unsigned long), 16);
		else if (fmt.modifier & F_DL)
			output = ft_ultoa_base(va_arg(*pa, unsigned long long), 16);
		else
			output = ft_ultoa_base(va_arg(*pa, size_t), 16);
		if (fmt.flag & F_SHARP && output[0] != '0')
		{
			ft_putstr("0X");
			more += 2;
		}
		pf->len_str = ft_strlen(output) + more;
		pf->fmt_str = output;
		print_flag_width(&fmt, pf);
		pf->ret += pf->len_str;
		free(output);
	}
	else if (fmt.type == T_U)
	{
		char	*str_num;

		if (fmt.modifier & F_SL)
			str_num = ft_ultoa_base(va_arg(*pa, unsigned long int), 10);
		else if (fmt.modifier & F_DL)
			str_num = ft_ultoa_base(va_arg(*pa, unsigned long long int), 10);
		else if (fmt.modifier & F_SH)
			str_num = ft_ustoa_base((unsigned short )va_arg(*pa,unsigned  int), 10);
		else if (fmt.modifier & F_DH)
			str_num = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 10);
		else if (fmt.modifier & F_Z)
			str_num = ft_ultoa_base(va_arg(*pa, size_t), 10);
		else
			str_num = ft_uitoa(va_arg(*pa, unsigned int));
		pf->len_str = ft_strlen(str_num);
		pf->fmt_str = str_num;
		print_flag_width(&fmt, pf);
		pf->ret += pf->len_str;
		free(str_num);
	}
	else if (fmt.type == T_GU)
	{
		char *output;

		output = ft_ultoa_base(va_arg(*pa, unsigned long), 10);
		ft_putstr(output);
		pf->ret += ft_strlen(output);
	}
}

void	init_printf(t_printf *pf, const char *format)
{
	pf->ret = 0;
	pf->str = format;
	pf->len_str = 0;
	pf->fmt_str = NULL;
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
