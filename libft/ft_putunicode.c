#include "libft.h"

int	ft_putunicode(const unsigned int cu)
{
	if (cu < 128)
	{
		ft_putchar(cu);
		return (1);
	}
	else if (cu < 2048)
	{
		ft_putchar(192 | (cu >> 6));
		ft_putchar(128 | (cu & 63));
		return(2);
	}
	else if (cu < 65536)
	{
		ft_putchar(224 | (cu >> 12));
		ft_putchar(128 | ((cu >> 6) & 63));
		ft_putchar(128 | (cu & 63));
		return(3);
	}
	else if (cu < 1114112)
	{
		ft_putchar(240 | (cu >> 18));
		ft_putchar(128 | ((cu >> 12) & 63));
		ft_putchar(128 | ((cu >> 6) & 63));
		ft_putchar(128 | (cu & 63));
		return(4);
	}
	return (0);
}
