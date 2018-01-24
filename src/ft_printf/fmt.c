#include "ft_printf.h"
#include "ftstdio.h"
#include "ftstring.h"

void	format_str(t_printf *pf, va_list *pa, t_formater *fmt)
{
	pf->w_str = va_arg(*pa, wchar_t *);
	if (fmt->precision)
		pf->ret += print_str_precision(fmt, pf);
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
			if ((fmt->modifier == F_SL) && !str_has_valid_codepoint(pf->w_str))
				pf->fmt_err = -1;
			pf->ret += print_str_regular(fmt, pf);
		}

	}
}

void	format_gstr(t_printf *pf, va_list *pa, t_formater *fmt)
{
	pf->w_str = va_arg(*pa, wchar_t *);
	if (fmt->precision)
		pf->ret += print_str_precision(fmt, pf);
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
			if ((fmt->modifier == F_SL) && !str_has_valid_codepoint(pf->w_str))
				pf->fmt_err = -1;
			pf->ret += print_str_regular(fmt, pf);
		}
	}
}

static void	fmt_d(t_printf *pf, va_list *pa, t_formater *fmt)
{
	long long int	num;

	num = va_arg(*pa, long long);
	if (fmt->modifier == F_SL)
		pf->fmt_str = ft_ltoa_base((long int ) num, 10);
	else if (fmt->modifier == F_DL)
		pf->fmt_str = ft_ltoa_base(num, 10);
	else if (fmt->modifier == F_SH)
		pf->fmt_str = ft_stoa_base((short )num, 10);
	else if (fmt->modifier == F_DH)
		pf->fmt_str = ft_ctoa_base((char )num, 10);
	else if (fmt->modifier == F_Z)
		pf->fmt_str = ft_ltoa_base(num, 10);
	else if (fmt->modifier == F_J)
		pf->fmt_str = ft_ltoa_base((intmax_t )num, 10);
	else
		pf->fmt_str = ft_itoa_base((int )num, 10);
}

void	format_d(t_printf *pf, va_list *pa, t_formater *fmt)
{

	fmt_d(pf, pa, fmt);
	if (fmt->flag & F_PLUS)
	{
		if (!is_neg(pf->fmt_str))
			pf->prefix = ft_strdup("+");
	}
	if (fmt->precision)
			pf->ret += print_with_precision(fmt, pf);
	else
		pf->ret += print_regular(fmt, pf);
	free(pf->fmt_str);
}

void	format_gd(t_printf *pf, va_list *pa, t_formater *fmt)
{
	long long 	n;

	n = va_arg(*pa, long long);
	pf->fmt_str = ft_ltoa_base(n, 10);
	if (fmt->flag & F_PLUS)
	{
		if (!is_neg(pf->fmt_str))
			pf->prefix = ft_strdup("+");
	}
	if (fmt->precision)
			pf->ret += print_with_precision(fmt, pf);
	else
		pf->ret += print_regular(fmt, pf);
	free(pf->fmt_str);
}
