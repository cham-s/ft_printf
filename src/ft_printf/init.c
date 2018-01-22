#include "ft_printf.h"

void		init_formater(t_formater *fmt)
{
	fmt->flag = 0;
	fmt->width = 0;
	fmt->modifier = 0;
	fmt->precision = 0;
	fmt->length = 0;
	fmt->type = 0;
}

void		init_printf(t_printf *pf, const char *format)
{
	pf->fmt_err = 0;
	pf->ret = 0;
	pf->str = format;
	pf->w_str = NULL;
	pf->prefix = NULL;
	pf->fmt_str = NULL;
}
