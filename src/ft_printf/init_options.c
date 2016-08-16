#include "ft_printf.h"

void	init_options(t_options *opt)
{
	opt->spec = 0;
	opt->flag = 0;
	opt->width = NULL;
	opt->precision = NULL;
	opt->length = ft_memalloc(4);
}

void	init_info(t_info *i)
{
	i->ret = 0;
	i->reg = NULL;
	i->spe = NULL;
	i->spe_uni = NULL;
	i->pos = 0;
	init_options(&i->options);
}
