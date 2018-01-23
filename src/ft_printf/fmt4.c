#include "ft_printf.h"
#include "ftstdio.h"
#include "ftstring.h"
#include "wchar.h"

void	format_x(t_printf *pf, va_list *pa, t_formater *fmt)
{
	if (fmt->modifier == F_DH)
		pf->fmt_str = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 16);
	else if (fmt->modifier == F_SH)
		pf->fmt_str = ft_ustoa_base((unsigned short)va_arg(*pa, unsigned int), 16);
	else if (fmt->modifier == F_SL)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long), 16);
	else if (fmt->modifier == F_DL)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long long), 16);
	else if (fmt->modifier == F_Z)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, size_t), 16);
	else if (fmt->modifier == F_J)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, uintmax_t), 16);
	else
		pf->fmt_str = ft_uitoa_base(va_arg(*pa, unsigned int), 16);
	str_tolower(pf->fmt_str);
	if (fmt->flag & F_SHARP)
	{
		if (ft_strcmp(pf->fmt_str, "0"))
			pf->prefix = ft_strdup("0x");
	}
	if (fmt->precision)
		pf->ret += print_with_precision(fmt, pf);
	else
		pf->ret += print_regular(fmt, pf);
	free(pf->fmt_str);
}

void	format_gx(t_printf *pf, va_list *pa, t_formater *fmt)
{
	if (fmt->modifier == F_DH)
		pf->fmt_str = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 16);
	else if (fmt->modifier == F_SH)
		pf->fmt_str = ft_ustoa_base((unsigned short)va_arg(*pa, unsigned int), 16);
	else if (fmt->modifier == F_SL)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long), 16);
	else if (fmt->modifier == F_DL)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long long), 16);
	else if (fmt->modifier == F_Z)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, size_t), 16);
	else if (fmt->modifier == F_J)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, uintmax_t), 16);
	else
		pf->fmt_str = ft_uitoa_base(va_arg(*pa, unsigned int), 16);
	if (fmt->flag & F_SHARP)
	{
		if (ft_strcmp(pf->fmt_str, "0"))
			pf->prefix = ft_strdup("0X");
	}
	if (fmt->precision)
		pf->ret += print_with_precision(fmt, pf);
	else
		pf->ret += print_regular(fmt, pf);
	free(pf->fmt_str);
}
