/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:50:07 by cattouma          #+#    #+#             */
/*   Updated: 2017/11/14 21:33:16 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ftstring.h"
#include "ftstdio.h"
#include "ftctype.h"
#include <unistd.h> 

typedef struct	s_printf
{
	int			ret;
	int			fmt_err;
	const char	*str;
	char		*fmt_str;
	char		invalid;
	size_t		len_str;
}				t_printf;

int				print_n_char(char c, int size)
{
	int ret;

	ret = 0;
	while (size--)
	{
		ft_putchar(c);
		ret += 1;
	}
	return (ret);
}

int				print_plus(t_formater *fmt, t_printf *pf)
{
	if (fmt->flag & F_PLUS)
	{
		if (pf->fmt_str[0] != '-')
		{
			ft_putchar('+');
			return (1);
		}
	}
	return (0);
}

int				final_size(int a, int b)
{
	int			size;
	size = 0;
	size = a - b;
	return (size = size < 0 ? 0 : size);
}


char			*str_tolower(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		*tmp = ft_tolower(*tmp);
		tmp++;
	}
	return (str);
}

int update_width(t_formater *fmt, t_printf *pf)
{
	if (fmt->flag & F_SHARP && pf->fmt_str[0] != '0')
	{
		if (fmt->type == T_O)
			return (fmt->width -= 1);
		else if (fmt->type == T_X || fmt->type == T_GX)
			return (fmt->width -= 2);
	}
	else if (fmt->type == T_P)
		return (fmt->width -= 2);
	return (fmt->width);
}

int prefix_sharp(t_formater *fmt, t_printf *pf)
{
	int ret;

	ret = 0;
	if (fmt->flag & F_SHARP && pf->fmt_str[0] != '0')
	{
		if (fmt->type == T_O || fmt->type == T_GO)
			ret += ft_putchar('0');
		else if (fmt->type == T_X)
			ret += ft_putstr("0x");
		else if (fmt->type == T_GX)
			ret += ft_putstr("0X");
		return (ret);
	}
	else if (fmt->type == T_P)
	{
		ret += ft_putstr("0x");
	}
	else if (pf->fmt_str[0] == '-')
	{
		ret += ft_putchar('-');
	}
	return (ret);
}

int				print_with_precision(t_formater *fmt, t_printf *pf)
{
	int		ret;
	int		size_width;
	int		size_precision;
	int		mixed_size;
	char	c;
	int		is_neg;

	ret = 0;
	c = '\0';
	is_neg = pf->fmt_str[0] == '-' ? 1 : 0;
	if (fmt->flag & F_BLANK || fmt->width > 0)
		c = ' ';
	if (fmt->flag & F_ZERO)
		c = '0';
	size_width = final_size(update_width(fmt, pf), (int )ft_strlen(pf->fmt_str));
	size_precision = final_size(fmt->length, (int )ft_strlen(pf->fmt_str));
	printf("\nfmt->length: %d\n str_len: %d\nsize precision: %d\n", fmt->length,(int )ft_strlen(pf->fmt_str), size_precision);
	exit(0);
	mixed_size = final_size(size_width, size_precision);
	if ((fmt->flag & F_ZERO || fmt->flag & F_BLANK || fmt->width > 0) && 
		!(fmt->flag & F_MINUS))
		ret += print_n_char(c, mixed_size);
	ret += prefix_sharp(fmt, pf);
	if ((pf->fmt_str[0] == '0' && *(pf->fmt_str + 1) == '\0'))
		if (fmt->length == 0)
			return (ret);
	ret += print_n_char('0', size_precision);
	ret += ft_putstr(is_neg? pf->fmt_str + 1 : pf->fmt_str);
	if ((fmt->flag & F_ZERO || fmt->flag & F_BLANK || fmt->width > 0) && 
		fmt->flag & F_MINUS)
		ret += print_n_char(c, mixed_size);
	return (ret);
}

int				print_regular(t_formater *fmt, t_printf *pf)
{
	int		ret;
	int		is_neg;
	char	c;
	int		size;

	ret = 0;
	size = final_size(fmt->width, (int )ft_strlen(pf->fmt_str));
	c = '\0';
	if (fmt->flag & F_BLANK || fmt->width > 0)
		c = ' ';
	if (fmt->flag & F_ZERO)
		c = '0';
	is_neg = pf->fmt_str[0] == '-' ? 1 : 0;
	if (fmt->flag & F_ZERO && is_neg)
	{
		ft_putchar('-');
		ret += 1;
	}
	if (fmt->flag & F_MINUS)
	{
		ret += ft_putstr(fmt->flag & F_ZERO && is_neg? pf->fmt_str + 1 : pf->fmt_str);
		ret += print_n_char(c, size);
	}
	else
	{
		ret += print_n_char(c, size);
		ret += ft_putstr(fmt->flag & F_ZERO && is_neg? pf->fmt_str + 1 : pf->fmt_str);
	}
	return (ret);
}

int				print_padding_str(t_formater *fmt, int size)
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
		if (fmt->modifier == F_SH)
			printf("h ");
		if (fmt->modifier == F_SL)
			printf("l ");
		if (fmt->modifier == F_DL)
			printf("ll ");
		if (fmt->modifier == F_DH)
			printf("hh ");
		if (fmt->modifier == F_Z)
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
	fmt->precision = 0;
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
		if ((fmt->flag & F_BLANK) && (fmt->flag & F_PLUS))
			fmt->flag &= 0b11011; /* Ignore F_BLANK */
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
		fmt->precision = 1;
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
			fmt->modifier = F_SL;
		else if (*(pf->str) == 'l' && *((pf->str) + 1) == 'l')
			fmt->modifier = F_DL;
		else if (*(pf->str) == 'h' && *((pf->str) + 1) != 'h')
			fmt->modifier = F_SH;
		else if (*(pf->str) == 'h' && *((pf->str) + 1) == 'h')
			fmt->modifier = F_DH;
		else if (*(pf->str) == 'z')
			fmt->modifier = F_Z;
		else if (*(pf->str) == 'j')
			fmt->modifier = F_J;
		if ((fmt->modifier == F_DL) || fmt->modifier == F_DH)
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
	else 
	{
		fmt->type = T_OTH;
		pf->invalid = *(pf->str);
		(pf->str)++;
	}
}

void		set_formater(t_formater *fmt, t_printf *pf, va_list *pa)
{
	set_flags(fmt, pf);
	while (*(pf->str) == '*' || ft_isdigit(*(pf->str)))
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
		wchar_t *str;
		int size;

		str = NULL;
		str = va_arg(*pa, wchar_t *);
		size = fmt.width - (fmt.modifier == F_SL ? ft_strunilen(str) : \
				ft_strlen((char *)str));
		size = size < 0 ? 0 : size;
		if (!str)
		{
			ft_putstr("(null)");
			pf->ret += NULL_LEN;
		}
		else
		{
			if ((fmt.modifier == F_SL) && !str_has_valid_codepoint(str))
				pf->fmt_err = -1;
			if(!(fmt.flag & F_MINUS))
			{
				pf->ret += print_padding_str(&fmt, size);
				pf->ret += fmt.modifier == F_SL ? ft_putstruni(str) : \
						   write(1, (char *)str, ft_strlen((char *)str));
			}
			else
			{
				pf->ret += fmt.modifier == F_SL ? ft_putstruni(str) : \
						   ft_putnstr((char *)str, ft_strlen((char *)str));
				pf->ret += print_padding_str(&fmt, size);
			}
		}
	}
	else if (fmt.type == T_GS)
	{
		wchar_t	*str;
		int size;

		str = va_arg(*pa, wchar_t *);
		size = fmt.width - ft_strunilen(str);
		size = size < 0 ? 0 : size;
		if (!str)
		{
			ft_putstr("(null)");
			pf->ret += NULL_LEN;
		}
		else
		{
			if (!str_has_valid_codepoint(str))
				pf->fmt_err = -1;
			if(!(fmt.flag & F_MINUS))
			{
				pf->ret += print_padding_str(&fmt, size);
				pf->ret +=  ft_putstruni(str);
			}
			else
			{
				pf->ret += ft_putstruni(str);
				pf->ret += print_padding_str(&fmt, size);
			}
		}
	}
	else if (fmt.type == T_D || fmt.type == T_I)
	{
		long long int	num;

		num = va_arg(*pa, long long);
		if (fmt.modifier == F_SL)
			pf->fmt_str = ft_ltoa_base((long int ) num, 10);
		else if (fmt.modifier == F_DL)
			pf->fmt_str = ft_ltoa_base(num, 10);
		else if (fmt.modifier == F_SH)
			pf->fmt_str = ft_stoa_base((short )num, 10);
		else if (fmt.modifier == F_DH)
			pf->fmt_str = ft_ctoa_base((char )num, 10);
		else if (fmt.modifier == F_Z)
			pf->fmt_str = ft_ltoa_base(num, 10);
		else if (fmt.modifier == F_J)
			pf->fmt_str = ft_ltoa_base((intmax_t )num, 10);
		else
			pf->fmt_str = ft_itoa_base((int )num, 10);
		pf->ret += print_plus(&fmt, pf);
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
			pf->ret += print_regular(&fmt, pf);
		free(pf->fmt_str);
	}
	else if (fmt.type == T_GD)
	{
		long long 	n;

		n = va_arg(*pa, long long);
		pf->fmt_str = ft_ltoa_base(n, 10);
		pf->ret += print_plus(&fmt, pf);
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
			pf->ret += print_regular(&fmt, pf);
		free(pf->fmt_str);
	}
	else if (fmt.type == T_P)
	{
		void				*n;
		unsigned long long	addr;

		n = va_arg(*pa, void*);
		addr = (unsigned long long)n;
		pf->fmt_str = ft_ltoa_base(addr, 16);
		str_tolower(pf->fmt_str);
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
		{
			pf->ret += ft_putstr("0x");
			fmt.width -= 2;
			pf->ret += print_regular(&fmt, pf);
		}
		free(pf->fmt_str);
	}
	else if (fmt.type == T_C)
	{
		int	ret;
		int size;

		ret = 0;
		size = fmt.width - 1;
		size = size < 0 ? 0 : size;
		if (!(fmt.flag & F_MINUS))
			pf->ret += print_padding_str(&fmt, size);
		if (fmt.modifier == F_SL)
		{
			ret = ft_putunicode(va_arg(*pa, wint_t));
			if (ret < 0)
				pf->fmt_err = -1;
			else
				pf->ret += ret;
		}
		else
			pf->ret += ft_putchar(va_arg(*pa, int));
		if (fmt.flag & F_MINUS)
			pf->ret += print_padding_str(&fmt, size);
	}
	else if (fmt.type == T_GC)
	{
		int	ret;
		ret = 0;
		int size;

		size = fmt.width - 1;
		size = size < 0 ? 0 : size;
		if (!(fmt.flag & F_MINUS))
			pf->ret += print_padding_str(&fmt, size);
		ret = ft_putunicode(va_arg(*pa, wint_t));
		if (ret < 0)
			pf->fmt_err = -1;
		else
			pf->ret += ret;
		if (fmt.flag & F_MINUS)
			pf->ret += print_padding_str(&fmt, size);
	}
	else if (fmt.type == T_O)
	{
		if (fmt.modifier == F_DH)
			pf->fmt_str = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 8);
		else if (fmt.modifier == F_SH)
			pf->fmt_str = ft_ustoa_base((unsigned short)va_arg(*pa, unsigned int), 8);
		else if (fmt.modifier == F_SL)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long), 8);
		else if (fmt.modifier == F_DL)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long long), 8);
		else if (fmt.modifier == F_Z)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, size_t), 8);
		else if (fmt.modifier == F_J)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, uintmax_t), 8);
		else
			pf->fmt_str = ft_uitoa_base(va_arg(*pa, unsigned int), 8);
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
		{
			if (fmt.flag & F_SHARP && pf->fmt_str[0] != '0')
			{
				pf->ret += ft_putstr("0");
				fmt.width -= 1;
			}
			pf->ret += print_regular(&fmt, pf);
		}
		free(pf->fmt_str);
	}
	else if (fmt.type == T_GO)
	{
		pf->fmt_str = ft_ltoa_base(va_arg(*pa, unsigned long), 8);
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
		{
			if (fmt.flag & F_SHARP && pf->fmt_str[0] != '0')
			{
				ft_putstr("0");
				pf->ret += 1;
			}
			pf->ret += print_regular(&fmt, pf);
		}
		free(pf->fmt_str);
	}
	else if (fmt.type == T_X)
	{
		if (fmt.modifier == F_DH)
			pf->fmt_str = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 16);
		else if (fmt.modifier == F_SH)
			pf->fmt_str = ft_ustoa_base((unsigned short)va_arg(*pa, unsigned int), 16);
		else if (fmt.modifier == F_SL)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long), 16);
		else if (fmt.modifier == F_DL)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long long), 16);
		else if (fmt.modifier == F_Z)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, size_t), 16);
		else if (fmt.modifier == F_J)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, uintmax_t), 16);
		else
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, size_t), 16);
		str_tolower(pf->fmt_str);
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
		{
			if (fmt.flag & F_SHARP && pf->fmt_str[0] != '0')
			{
				pf->ret += ft_putstr("0x");
				fmt.width -= 2;
			}
			pf->ret += print_regular(&fmt, pf);
		}
		free(pf->fmt_str);
	}
	else if (fmt.type == T_GX)
	{
		if (fmt.modifier == F_DH)
			pf->fmt_str = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 16);
		else if (fmt.modifier == F_SH)
			pf->fmt_str = ft_ustoa_base((unsigned short)va_arg(*pa, unsigned int), 16);
		else if (fmt.modifier == F_SL)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long), 16);
		else if (fmt.modifier == F_DL)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long long), 16);
		else if (fmt.modifier == F_Z)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, size_t), 16);
		else if (fmt.modifier == F_J)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, uintmax_t), 16);
		else
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, size_t), 16);
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
		{
			if (fmt.flag & F_SHARP && pf->fmt_str[0] != '0')
			{
				pf->ret += ft_putstr("0X");
			}
			pf->ret += print_regular(&fmt, pf);
		}
		free(pf->fmt_str);
	}
	else if (fmt.type == T_U)
	{

		if (fmt.modifier == F_SL)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long int), 10);
		else if (fmt.modifier == F_DL)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long long int), 10);
		else if (fmt.modifier == F_SH)
			pf->fmt_str = ft_ustoa_base((unsigned short )va_arg(*pa,unsigned  int), 10);
		else if (fmt.modifier == F_DH)
			pf->fmt_str = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 10);
		else if (fmt.modifier == F_Z)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, size_t), 10);
		else if (fmt.modifier == F_J)
			pf->fmt_str = ft_ultoa_base(va_arg(*pa, uintmax_t), 10);
		else
			pf->fmt_str = ft_uitoa(va_arg(*pa, unsigned int));
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
			pf->ret += print_regular(&fmt, pf);
		free(pf->fmt_str);
	}
	else if (fmt.type == T_GU)
	{
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long), 10);
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
			pf->ret += print_regular(&fmt, pf);
		free(pf->fmt_str);
	}
	else if (fmt.type == T_OTH)
	{
		pf->fmt_str = ft_strnew(1);
		pf->fmt_str[0] = pf->invalid;
		pf->ret += print_regular(&fmt, pf);
		free(pf->fmt_str);
	}
}

void	init_printf(t_printf *pf, const char *format)
{
	pf->fmt_err = 0;
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
		return (write(1, "(null)", 6));
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
	return (pf.fmt_err < 0 ? - 1: pf.ret);
}
