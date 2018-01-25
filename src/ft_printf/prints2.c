#include "ft_printf.h"
#include "ftstring.h"
#include "ftstdio.h"

static int		print_w_pres2(t_formater *fmt, t_printf *pf, int z_sz, int b_sz)
{
	int			ret;
	int			is_nega;

	is_nega = pf->fmt_str[0] == '-' ? 1 : 0;
	ret = 0;
	if (pf->prefix != NULL)
	{
		free(pf->prefix);
		pf->prefix = NULL;
	}
	ret += print_n_char('0', z_sz);
	if (ft_strcmp(pf->fmt_str, "0") || \
			(!ft_strcmp(pf->fmt_str, "0") && fmt->length > 0))
		ret += ft_putstr(is_nega? pf->fmt_str + 1 : pf->fmt_str);
	if ((fmt->flag & F_ZERO || fmt->flag & F_BLANK || fmt->width > 0) &&
		fmt->flag & F_MINUS)
		ret += print_n_char(' ', b_sz);
	return (ret);
}

static int		print_w_pres3(t_formater *fmt, t_printf *pf)
{
	int			ret;
	int			is_nega;
	int			b_size;
	int			z_size;

	is_nega = pf->fmt_str[0] == '-' ? 1 : 0;
	ret = 0;
	z_size = final_size(fmt->length, ft_strlen(is_nega? pf->fmt_str + 1 :\
			   	pf->fmt_str));
	if (ft_strcmp(pf->fmt_str, "0") || \
		(!ft_strcmp(pf->fmt_str, "0") && fmt->length  > 0))
		b_size = final_size(fmt->width, z_size + ft_strlen(pf->prefix) + \
				ft_strlen(is_nega? pf->fmt_str + 1 : pf->fmt_str));
	else
		b_size = final_size(fmt->width, z_size + ft_strlen(pf->prefix));
	if ((!(fmt->flag & F_MINUS) && !(fmt->flag & F_ZERO)) || \
		   	(fmt->flag & F_ZERO))
		ret += print_n_char(' ',b_size);
	ret += ft_putstr(pf->prefix);
	ret += print_w_pres2(fmt, pf, z_size, b_size);
	return (ret);
}

int				print_with_precision(t_formater *fmt, t_printf *pf)
{
	int			is_nega;
	int			ret;

	ret = 0;
	is_nega = pf->fmt_str[0] == '-' ? 1 : 0;
	if (is_nega)
		pf->prefix = ft_strdup("-");
	if (is_signed(fmt) && fmt->flag & F_BLANK && !is_neg(pf->fmt_str))
	{
		ret += ft_putchar(' ');
		fmt->width -= 1;
	}
	ret += print_w_pres3(fmt, pf);
	return (ret);
}

int				print_reg2(t_formater *fmt, t_printf *pf, int size)
{
	int			ret = 0;
	int			is_nega;


	is_nega = pf->fmt_str[0] == '-' ? 1 : 0;
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
	size = final_size(fmt->width, ft_strlen(is_nega? pf->fmt_str + 1 : \
				pf->fmt_str) + ft_strlen(pf->prefix));
	if (!(fmt->flag & F_MINUS) && !(fmt->flag & F_ZERO))
		ret += print_n_char(' ', size);
	ret += ft_putstr(pf->prefix);
	ret += print_reg2(fmt, pf, size);
	return (ret);
}
