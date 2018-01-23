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
		format_str(pf, pa, &fmt);
	}
	else if (fmt.type == T_GS)
	{
		format_gstr(pf, pa, &fmt);
	}
	else if (fmt.type == T_D || fmt.type == T_I)
	{
		format_d(pf, pa, &fmt);
	}
	else if (fmt.type == T_GD)
	{
		format_gd(pf, pa, &fmt);
	}
	else if (fmt.type == T_P)
	{
		format_p(pf, pa, &fmt);
	}
	else if (fmt.type == T_C)
	{
		format_c(pf, pa, &fmt);
	}
	else if (fmt.type == T_GC)
	{
		format_gc(pf, pa, &fmt);
	}
	else if (fmt.type == T_O)
	{
		format_o(pf, pa, &fmt);
	}
	else if (fmt.type == T_GO)
	{
		format_go(pf, pa, &fmt);
	}
	else if (fmt.type == T_X)
	{
		format_x(pf, pa, &fmt);
	}
	else if (fmt.type == T_GX)
	{
		format_gx(pf, pa, &fmt);
	}
	else if (fmt.type == T_U)
	{
		format_u(pf, pa, &fmt);
	}
	else if (fmt.type == T_GU)
	{
		format_gu(pf, pa, &fmt);
	}
	else if (fmt.type == T_OTH)
	{
		format_oth(pf, pa, &fmt);
	}
}
