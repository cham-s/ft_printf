#include "libft.h"

static unsigned char	conv(unsigned char n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

static	unsigned char		ft_size(unsigned char n, unsigned char base)
{
	unsigned char		s;

	s = 0;
	while (n)
	{
		s++;
		n /= base;
	}
	return (s);
}

char			*ft_uctoa_base(unsigned char n, unsigned char base)
{
	unsigned char		s;
	unsigned char		tmp;
	char	*new;

	if (n == 0)
		s = 1;
	else
		s = ft_size(n, base);
	if (!(new = ft_strnew(s)))
		return (NULL);
	while (s--)
	{
		tmp = n % base;
		new[s] = conv(tmp);
		n /= base;
	}
	return (new);
}
