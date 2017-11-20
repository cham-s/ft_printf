
#include "ftstdio.h"
#include "ftstring.h"

static char	conv(char n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

static	int		ft_size(char n, char base)
{
	char		s;

	s = 0;
	while (n)
	{
		s++;
		n /= base;
	}
	return (s);
}

static	char	*ft_ismaxchar_or_zero(char n, char base)
{
	char	*ret;

	ret = NULL;
	if (n == -128 && base == 10)
	{
		ret = ft_strnew(ft_strlen("-128"));
		if (!ret)
			return (NULL);
		ft_memcpy(ret, "-128", ft_strlen("-128"));
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

char			*ft_ctoa_base(char n, char base)
{
	int			s;
	int			t;
	int			tmp;
	char		*new;

	s = ft_size(n, base);
	t = n;
	if (n == 0 || n == -128)
		return (ft_ismaxchar_or_zero(n, base));
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
