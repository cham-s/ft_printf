#include "libft.h"

int	ft_putunicode(wint_t c)
{
	if (c <= 0x0000007f)
	{
		ft_putchar(c);
		return (1);
	}
	else if (c <= 0x000007ff)
	{
		ft_putchar(0xc0 | (c >> 6));
		ft_putchar(0x80 | (c & 0x3f));
		return(2);
	}
	else if (c <= 0x0000ffff)
	{
		ft_putchar(0xe0 | (c >> 12));
		ft_putchar(0x80 | ((c >> 6) & 0x3f));
		ft_putchar(0x80 | (c & 0x3f));
		return(3);
	}
	else if (c <= 0x0010ffff)
	{
		ft_putchar(0xf0 |  (c >> 18));
		ft_putchar(0x80 | ((c >> 12) & 0x3f));
		ft_putchar(0x80 | ((c >> 6) & 0x3f));
		ft_putchar(0x80 | (c & 0x3f));
		return(4);
	}
	return (-1);
}
