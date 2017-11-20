
#include "ftstdio.h"
#include "ftstring.h"

static short	conv(short n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

static	short		ft_size(short n, short base)
{
	short		s;

	s = 0;
	while (n)
	{
		s++;
		n /= base;
	}
	return (s);
}

static	char	*ft_ismaxshort_or_zero(short n, short base)
{
	char	*ret;

	ret = NULL;
	if (n == -32768 && base == 10)
	{
		ret = ft_strnew(ft_strlen("-32768"));
		if (!ret)
			return (NULL);
		ft_memcpy(ret, "-32768", ft_strlen("-32768"));
	}
	else
	{
		ret = ft_strnew(ft_strlen("0"));
		if (!ret)
			return (NULL);
		ft_memcpy(ret, "0", ft_strlen("0"));
	}
	return (ret);
}

char			*ft_stoa_base(short n, short base)
{
	short		s;
	short		t;
	short		tmp;
	char	*new;

	s = ft_size(n, base);
	t = n;
	if (n == 0 || n == -32768)
		return (ft_ismaxshort_or_zero(n, base));
	if (n < 0)
	{
		n = -n;
		s++;
	}
	if (!(new = ft_strnew(s)))
		return (NULL);
	while (s--)
	{
		tmp = n % base;
		new[s] = conv(tmp);
		n /= base;
	}
	new[0] = (t < 0 ? '-' : new[0]);
	return (new);
}
