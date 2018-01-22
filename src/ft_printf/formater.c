#include "ft_printf.h"
#include "ftstring.h"
#include "ftstdio.h"

void		handle_format_string(t_printf *pf, va_list *pa)
{
	t_formater	fmt;

	init_formater(&fmt);
	(pf->str)++;
	set_formater(&fmt, pf, pa);
	if (fmt.type == T_PNT)
	{
		pf->w_str = (wchar_t *)ft_strdup("%");
		if (fmt.precision)
			pf->ret += print_str_precision(&fmt, pf);
		else
			pf->ret += print_str_regular(&fmt, pf);
		free(pf->w_str);
	}
	else if (fmt.type == T_S)
	{
		pf->w_str = va_arg(*pa, wchar_t *);
		if (fmt.precision)
			pf->ret += print_str_precision(&fmt, pf);
		else
		{
			if (!pf->w_str)
			{
				ft_putstr("(null)");
				pf->ret += NULL_LEN;
			}
			// return instead when function
			else
			{
				if ((fmt.modifier == F_SL) && !str_has_valid_codepoint(pf->w_str))
					pf->fmt_err = -1;
				pf->ret += print_str_regular(&fmt, pf);
			}

		}
	}
	else if (fmt.type == T_GS)
	{
		pf->w_str = va_arg(*pa, wchar_t *);
		if (fmt.precision)
			pf->ret += print_str_precision(&fmt, pf);
		else
		{
			if (!pf->w_str)
			{
				ft_putstr("(null)");
				pf->ret += NULL_LEN;
			}
			// return instead when function
			else
			{
				if ((fmt.modifier == F_SL) && !str_has_valid_codepoint(pf->w_str))
					pf->fmt_err = -1;
				pf->ret += print_str_regular(&fmt, pf);
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
		if (fmt.flag & F_PLUS)
		{
			if (!is_neg(pf->fmt_str))
				pf->prefix = ft_strdup("+");
		}
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
		if (fmt.flag & F_PLUS)
		{
			if (!is_neg(pf->fmt_str))
				pf->prefix = ft_strdup("+");
		}
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
		pf->prefix = ft_strdup("0x");
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
			pf->ret += print_regular(&fmt, pf);
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
		{
			if (fmt.flag & F_SHARP && !fmt.length)
				pf->prefix = ft_strdup("0");
			pf->ret += print_with_precision(&fmt, pf);
		}
		else
		{
			if (fmt.flag & F_SHARP)
			{
				if (ft_strcmp(pf->fmt_str, "0"))
					pf->prefix = ft_strdup("0");
			}
			pf->ret += print_regular(&fmt, pf);
		}
		free(pf->fmt_str);
	}
	else if (fmt.type == T_GO)
	{
		pf->fmt_str = ft_ltoa_base(va_arg(*pa, unsigned long), 8);
		if (fmt.precision)
		{
			if (fmt.flag & F_SHARP && !fmt.length)
				pf->prefix = ft_strdup("0");
			pf->ret += print_with_precision(&fmt, pf);
		}
		else
		{
			if (fmt.flag & F_SHARP)
			{
				if (ft_strcmp(pf->fmt_str, "0"))
					pf->prefix = ft_strdup("0");
			}
			pf->ret += print_regular(&fmt, pf);
		}
		if (fmt.flag & F_SHARP)
		{
			if (ft_strcmp(pf->fmt_str, "0"))
				pf->prefix = ft_strdup("0");
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
			pf->fmt_str = ft_uitoa_base(va_arg(*pa, unsigned int), 16);
		str_tolower(pf->fmt_str);
		if (fmt.flag & F_SHARP)
		{
			if (ft_strcmp(pf->fmt_str, "0"))
				pf->prefix = ft_strdup("0x");
		}
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
			pf->ret += print_regular(&fmt, pf);
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
			pf->fmt_str = ft_uitoa_base(va_arg(*pa, unsigned int), 16);
		if (fmt.flag & F_SHARP)
		{
			if (ft_strcmp(pf->fmt_str, "0"))
				pf->prefix = ft_strdup("0X");
		}
		if (fmt.precision)
			pf->ret += print_with_precision(&fmt, pf);
		else
			pf->ret += print_regular(&fmt, pf);
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
