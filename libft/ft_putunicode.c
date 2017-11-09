#include "libft.h"

int	ft_putunicode(const unsigned int cp)
{
	int	i;

	i = 0;
	if (cp < 0x0000007f)
	{
		ft_putchar(cp);
		return (1);
	}
	else if (cp < 0x000007ff)
	{
		ft_putchar(0xc0 | (cp >> 6));
		ft_putchar(0x80 | (cp & 0x3f));
		return(2);
	}
	else if (cp < 0x0000ffff)
	{
		ft_putchar(0xe0 | (cp >> 12));
		ft_putchar(0x80 | ((cp >> 6) & 0x3f));
		ft_putchar(0x80 | (cp & 0x3f));
		return(3);
	}
	else if (cp < 0x001fffff)
	{
		ft_putchar(0xf0 |  (cp >> 18));
		ft_putchar(0x80 | ((cp >> 12) & 0x3f));
		ft_putchar(0x80 | ((cp >> 6) & 0x3f));
		ft_putchar(0x80 | (cp & 0x3f));
		return(4);
	}
	return (0);
}
