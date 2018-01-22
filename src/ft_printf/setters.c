#include "ft_printf.h"
#include "ftstring.h"
#include "ftctype.h"
#include "ftstdio.h"

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
		if (fmt->width < 0)
		{
			fmt->width = -fmt->width;
			fmt->flag |= F_MINUS;
		}
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
