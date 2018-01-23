#include "ft_printf.h"
#include "ftstdio.h"
#include "ftstring.h"

void	format_u(t_printf *pf, va_list *pa, t_formater *fmt)
{
	if (fmt->modifier == F_SL)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long int), 10);
	else if (fmt->modifier == F_DL)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long long int), 10);
	else if (fmt->modifier == F_SH)
		pf->fmt_str = ft_ustoa_base((unsigned short )va_arg(*pa,unsigned  int), 10);
	else if (fmt->modifier == F_DH) pf->fmt_str = ft_uctoa_base((unsigned char )va_arg(*pa, unsigned int), 10); else if (fmt->modifier == F_Z) pf->fmt_str = ft_ultoa_base(va_arg(*pa, size_t), 10);
	else if (fmt->modifier == F_J)
		pf->fmt_str = ft_ultoa_base(va_arg(*pa, uintmax_t), 10);
	else
		pf->fmt_str = ft_uitoa(va_arg(*pa, unsigned int));
	if (fmt->precision)
		pf->ret += print_with_precision(fmt, pf);
	else
		pf->ret += print_regular(fmt, pf);
	free(pf->fmt_str);
}

void	format_gu(t_printf *pf, va_list *pa, t_formater *fmt)
{
	pf->fmt_str = ft_ultoa_base(va_arg(*pa, unsigned long), 10);
	if (fmt->precision)
		pf->ret += print_with_precision(fmt, pf);
	else
		pf->ret += print_regular(fmt, pf);
	free(pf->fmt_str);
}

void	format_oth(t_printf *pf, va_list *pa, t_formater *fmt)
{
		(void)pa;
		pf->fmt_str = ft_strnew(1);
		pf->fmt_str[0] = pf->invalid;
		pf->ret += print_regular(fmt, pf);
		free(pf->fmt_str);
}
