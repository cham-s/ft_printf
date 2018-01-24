#include "ft_printf.h"
#include "ftstring.h"
#include "ftstdio.h"

void	format_p(t_printf *pf, va_list *pa, t_formater *fmt)
{
	void				*n;
	unsigned long long	addr;

	n = va_arg(*pa, void*);
	addr = (unsigned long long)n;
	pf->fmt_str = ft_ltoa_base(addr, 16);
	str_tolower(pf->fmt_str);
	pf->prefix = ft_strdup("0x");
	if (fmt->precision)
		pf->ret += print_with_precision(fmt, pf);
	else
		pf->ret += print_regular(fmt, pf);
	free(pf->fmt_str);
}

void	format_c(t_printf *pf, va_list *pa, t_formater *fmt)
{
	int	ret;
	int size;

	ret = 0;
	size = fmt->width - 1;
	size = size < 0 ? 0 : size;
	if (!(fmt->flag & F_MINUS))
		pf->ret += print_padding_str(fmt, size);
	if (fmt->modifier == F_SL)
	{
		ret = ft_putunicode(va_arg(*pa, wint_t));
		if (ret < 0)
			pf->fmt_err = -1;
		else
			pf->ret += ret;
	}
	else
		pf->ret += ft_putchar(va_arg(*pa, int));
	if (fmt->flag & F_MINUS)
		pf->ret += print_padding_str(fmt, size);
}

void	format_gc(t_printf *pf, va_list *pa, t_formater *fmt)
{
	int	ret;
	ret = 0;
	int size;

	size = fmt->width - 1;
	size = size < 0 ? 0 : size;
	if (!(fmt->flag & F_MINUS))
		pf->ret += print_padding_str(fmt, size);
	ret = ft_putunicode(va_arg(*pa, wint_t));
	if (ret < 0)
		pf->fmt_err = -1;
	else
		pf->ret += ret;
	if (fmt->flag & F_MINUS)
		pf->ret += print_padding_str(fmt, size);
}

static void	fmt_o(t_printf *pf, va_list *pa, t_formater *fmt)
{
	if (fmt->modifier == F_DH)
		pf->fmt_str = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 8);
	else if (fmt->modifier == F_SH)
		pf->fmt_str = ft_ustoa_base((unsigned short)va_arg(*pa, unsigned int), 8);
	else if (fmt->modifier == F_SL)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long), 8);
	else if (fmt->modifier == F_DL)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long long), 8);
	else if (fmt->modifier == F_Z)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, size_t), 8);
	else if (fmt->modifier == F_J)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, uintmax_t), 8);
	else
		pf->fmt_str = ft_uitoa_base(va_arg(*pa, unsigned int), 8);
}

void	format_o(t_printf *pf, va_list *pa, t_formater *fmt)
{
	fmt_o(pf, pa, fmt);
	if (fmt->precision)
	{
		if (fmt->flag & F_SHARP && !fmt->length)
			pf->prefix = ft_strdup("0");
		pf->ret += print_with_precision(fmt, pf);
	}
	else
	{
		if (fmt->flag & F_SHARP)
		{
			if (ft_strcmp(pf->fmt_str, "0"))
				pf->prefix = ft_strdup("0");
		}
		pf->ret += print_regular(fmt, pf);
	}
	free(pf->fmt_str);
}

void	format_go(t_printf *pf, va_list *pa, t_formater *fmt)
{
	pf->fmt_str = ft_ltoa_base(va_arg(*pa, unsigned long), 8);
	if (fmt->precision)
	{
		if (fmt->flag & F_SHARP && !fmt->length)
			pf->prefix = ft_strdup("0");
		pf->ret += print_with_precision(fmt, pf);
	}
	else
	{
		if (fmt->flag & F_SHARP)
		{
			if (ft_strcmp(pf->fmt_str, "0"))
				pf->prefix = ft_strdup("0");
		}
		pf->ret += print_regular(fmt, pf);
	}
	if (fmt->flag & F_SHARP)
	{
		if (ft_strcmp(pf->fmt_str, "0"))
			pf->prefix = ft_strdup("0");
	}
	free(pf->fmt_str);
}
