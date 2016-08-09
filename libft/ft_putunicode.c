#include "libft.h"

int	ft_putunicode(const unsigned int cp)
{
	int	i;

	i = 0;
	if (cp < 128)
	{
		ft_putchar(cp);
		return (1);
	}
	else if (cp < 2048)
	{
		ft_putchar(192 | (cp >> 6));
		ft_putchar(128 | (cp & 63));
		return(2);
	}
	else if (cp < 65536)
	{
		ft_putchar(224 | (cp >> 12));
		ft_putchar(128 | ((cp >> 6) & 63));
		ft_putchar(128 | (cp & 63));
		return(3);
	}
	else if (cp < 1114112)
	{
		ft_putchar(240 | (cp >> 18));
		ft_putchar(128 | ((cp >> 12) & 63));
		ft_putchar(128 | ((cp >> 6) & 63));
		ft_putchar(128 | (cp & 63));
		return(4);
	}
	return (0);
}
