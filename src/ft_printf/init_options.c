#include "ft_printf.h"

void	init_options(t_options *opt)
{
	opt->has_flags = 0;
	opt->has_width = 0;
	opt->has_precision = 0;
	opt->has_length = 0;
}
