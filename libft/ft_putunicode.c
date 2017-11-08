#include "libft.h"

int	ft_putunicode(const unsigned int cp)
{
	int	i;

	i = 0;
	if (cp < 0x0000007F)
	{
		ft_putchar(cp);
		return (1);
	}
	else if (cp < 0x000007FF)
	{
		ft_putchar(192 | (cp >> 6));
		ft_putchar(128 | (cp & 63));
		return(2);
	}
	else if (cp < 0x0000FFFF)
	{
		ft_putchar(224 | (cp >> 12));
		ft_putchar(128 | ((cp >> 6) & 63));
		ft_putchar(128 | (cp & 63));
		return(3);
	}
	else if (cp < 0x001FFFFF)
	{
		ft_putchar(240 | (cp >> 18));
		ft_putchar(128 | ((cp >> 12) & 63));
		ft_putchar(128 | ((cp >> 6) & 63));
		ft_putchar(128 | (cp & 63));
		return(4);
	}
	return (0);
}
