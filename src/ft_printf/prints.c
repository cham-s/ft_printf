#include "ft_printf.h"
#include "ftstring.h"
#include "ftstdio.h"
#include "ftctype.h"
#include <stdlib.h>

int				printable_size(wchar_t *str, int n)
{
	int size;

	size = 0;
	while (n > size_bytes_code_point(*str) || n == size_bytes_code_point(*str))
	{
		size += size_bytes_code_point(*str);
		n -= size_bytes_code_point(*str);
		str++;
	}
	return (size);
}

int				print_str_precision(t_formater *fmt, t_printf *pf)
{
	int		ret;
	int		c_size;
	char	c;
	size_t len;

	c = '\0';
	ret = 0;
	if (fmt->flag & F_ZERO)
		c = '0';
	else if (fmt->width > 0)
		c = ' ';
	len = fmt->modifier == F_SL || fmt->type == T_GS ? ft_strunilen(pf->w_str): \
		  ft_strlen((char *)pf->w_str);
	if (fmt->type == T_PNT)
		len = 1;
	else
		len = (int )len < fmt->length ? len : fmt->length;
	len = fmt->modifier == F_SL || fmt->type == T_GS ? printable_size(pf->w_str, len) : len;
	c_size = fmt->width - len;
	c_size = c_size < 0 ? 0 : c_size;
	if (!(fmt->flag & F_MINUS) && c != '\0')
		ret += print_n_char(c, c_size);
	ret += fmt->modifier == F_SL || fmt->type == T_GS ? \
		   ft_putstrnuni(pf->w_str, len) : ft_putnstr((char *)pf->w_str, len);
	if (fmt->flag & F_MINUS && c != '\0')
		ret += print_n_char(c, c_size);
	return (ret);
}

int				print_str_regular(t_formater *fmt, t_printf *pf)
{
	int		ret;
	int		c_size;
	char	c;

	c = '\0';
	ret = 0;
	if (fmt->flag & F_ZERO)
		c = '0';
	else if (fmt->width > 0)
		c = ' ';
	c_size = fmt->width - (fmt->modifier == F_SL || fmt->type == T_GS ? \
		   	ft_strunilen(pf->w_str) : ft_strlen((char *)pf->w_str));
	c_size = c_size < 0 ? 0 : c_size;
	if (!(fmt->flag & F_MINUS))
		ret += print_n_char(c, c_size);
	ret += fmt->modifier == F_SL || fmt->type == T_GS ? \
		   ft_putstruni(pf->w_str) : ft_putstr((char *)pf->w_str) ;
	if (fmt->flag & F_MINUS)
		ret += print_n_char(c, c_size);
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
