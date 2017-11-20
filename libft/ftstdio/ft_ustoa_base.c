#include "ftstdio.h"
#include "ftstring.h"

static unsigned short	conv(unsigned short n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

static	unsigned short		ft_size(unsigned short n, unsigned short base)
{
	unsigned short		s;

	s = 0;
	while (n)
	{
		s++;
		n /= base;
	}
	return (s);
}

char			*ft_ustoa_base(unsigned short n, unsigned short base)
{
	unsigned short		s;
	unsigned short		tmp;
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
