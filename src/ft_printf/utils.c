#include "ft_printf.h"
#include "ftctype.h"
#include "ftstdio.h"

int is_signed(t_formater *fmt)
{
	return (fmt->type == T_D ||
		   	fmt->type == T_I ||
		   	fmt->type == T_GD);
}

int is_neg(char *str)
{
	return (str[0] == '-' ? 1 : 0);
}

int				final_size(int a, int b)
{
	int			size;
	size = 0;
	size = a - b;
	return (size = size < 0 ? 0 : size);
}

int				print_n_char(char c, int size)
{
	int ret;

	ret = 0;
	while (size--)
	{
		ft_putchar(c);
		ret += 1;
	}
	return (ret);
}

char			*str_tolower(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		*tmp = ft_tolower(*tmp);
		tmp++;
	}
	return (str);
}
