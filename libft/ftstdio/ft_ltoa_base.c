#include "libft.h"

static int	conv(int n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

char	*ft_ltoa_base(long long value, unsigned long long base)
{
	int					i;
	int 				is_neg;
	unsigned long long	tmp;
	char				*s;

	if (value == (-9223372036854775807 - 1) && base == 10)
		return ft_strdup("-9223372036854775808");
	if (base == 10 && value < 0)
		is_neg = 1;
	else
		is_neg = 0;
	if (value < 0)
		value = -value;
	tmp = value;
	i = 0;
	while (tmp >= base)
	{
		tmp /= base;
		i++;
	}
	if (is_neg)
	{
		i++;
		s = (char *)malloc(sizeof(char) * i + 1);
	}
	else
		s = (char *)malloc(sizeof(char) * i + 1);
	s[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		if (is_neg && i == 0)
			s[i] = '-';
		else
			s[i] = conv(tmp);
		value /= base;
		i--;
	}
	return (s);
}
