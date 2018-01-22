#include "ft_printf.h"
#include "ftstring.h"
#include "ftstdio.h"
#include "ftctype.h"
#include <stdlib.h>

int				print_with_precision(t_formater *fmt, t_printf *pf)
{
	int		ret;
	int		is_nega;
	int		b_size;
	int		z_size;

	ret = 0;
	is_nega = pf->fmt_str[0] == '-' ? 1 : 0;
	if (is_nega)
		pf->prefix = ft_strdup("-");
	if (is_signed(fmt) && fmt->flag & F_BLANK && !is_neg(pf->fmt_str))
	{
		ret += ft_putchar(' ');
		fmt->width -= 1;
	}
	z_size = final_size(fmt->length, ft_strlen(is_nega? pf->fmt_str + 1 : pf->fmt_str));
	if (ft_strcmp(pf->fmt_str, "0") || (!ft_strcmp(pf->fmt_str, "0") && fmt->length  > 0))
		b_size = final_size(fmt->width, z_size + ft_strlen(pf->prefix) + ft_strlen(is_nega? pf->fmt_str + 1 : pf->fmt_str));
	else
		b_size = final_size(fmt->width, z_size + ft_strlen(pf->prefix));
	if ((!(fmt->flag & F_MINUS) && !(fmt->flag & F_ZERO)) || (fmt->flag & F_ZERO))
		ret += print_n_char(' ',b_size);
	ret += ft_putstr(pf->prefix);
	if (pf->prefix != NULL)
	{
		free(pf->prefix);
		pf->prefix = NULL;
	}
	ret += print_n_char('0', z_size);
	if (ft_strcmp(pf->fmt_str, "0") || (!ft_strcmp(pf->fmt_str, "0") && fmt->length > 0))
		ret += ft_putstr(is_nega? pf->fmt_str + 1 : pf->fmt_str);
	if ((fmt->flag & F_ZERO || fmt->flag & F_BLANK || fmt->width > 0) &&
		fmt->flag & F_MINUS)
		ret += print_n_char(' ', b_size);
	return (ret);
}

int				print_regular(t_formater *fmt, t_printf *pf)
{
	int		ret;
	int		is_nega;
	int		size;

	ret = 0;
	is_nega = pf->fmt_str[0] == '-' ? 1 : 0;
	if (is_nega)
		pf->prefix = ft_strdup("-");
	if (is_signed(fmt) && fmt->flag & F_BLANK && !is_neg(pf->fmt_str))
	{
		ret += ft_putchar(' ');
		fmt->width -= 1;
	}
	size = final_size(fmt->width, ft_strlen(is_nega? pf->fmt_str + 1 : pf->fmt_str) + ft_strlen(pf->prefix));
	if (!(fmt->flag & F_MINUS) && !(fmt->flag & F_ZERO))
		ret += print_n_char(' ', size);
	ret += ft_putstr(pf->prefix);
	if (pf->prefix != NULL)
	{
		free(pf->prefix);
		pf->prefix = NULL;
	}
	if (fmt->flag & F_ZERO)
		ret += print_n_char('0', size);
	ret += ft_putstr(is_nega? pf->fmt_str + 1 : pf->fmt_str);
	if ((fmt->flag & F_BLANK || fmt->width > 0) && fmt->flag & F_MINUS)
		ret += print_n_char(' ', size);
	return (ret);
}

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
