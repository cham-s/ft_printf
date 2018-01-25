#include "ft_printf.h"
#include "ftctype.h"

static void		set_type2(t_formater *fmt, t_printf *pf)
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
		else if (*(pf->str) == 'u')
			fmt->type = T_U;
		else if (*(pf->str) == 'U')
			fmt->type = T_GU;
		else if (*(pf->str) == 'x')
			fmt->type = T_X;
		else
			return ;
}
void		set_type(t_formater *fmt, t_printf *pf)
{
	if (is_type(*(pf->str)))
	{
		set_type2(fmt, pf);
		if (*(pf->str) == 'O')
			fmt->type = T_GO;
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
	if (fmt->length < 0)
		fmt->precision = 0;
}
