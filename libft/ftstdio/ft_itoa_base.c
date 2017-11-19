/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 03:07:10 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/09 02:27:22 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conv(int n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

static	int		ft_size(int n, int base)
{
	int		s;

	s = 0;
	while (n)
	{
		s++;
		n /= base;
	}
	return (s);
}

static	char	*ft_ismaxint_or_zero(int n, int base)
{
	char	*ret;

	ret = NULL;
	if (n == -2147483648 && base == 10)
	{
		ret = ft_strnew(ft_strlen("-2147483648"));
		if (!ret)
			return (NULL);
		ft_memcpy(ret, "-2147483648", ft_strlen("-2147483648"));
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

char			*ft_itoa_base(int n, int base)
{
	int		s;
	int		t;
	int		tmp;
	char	*new;

	s = ft_size(n, base);
	t = n;
	if (n == 0 || n == -2147483648)
		return (ft_ismaxint_or_zero(n, base));
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
