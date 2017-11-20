/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 02:33:16 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/09 03:08:32 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstdio.h"
#include "ftstring.h"

static unsigned long long	conv(unsigned long long n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

static	unsigned long long		ft_size(unsigned long long n, unsigned long long base)
{
	unsigned long long		s;

	s = 0;
	while (n)
	{
		s++;
		n /= base;
	}
	return (s);
}

char			*ft_ultoa_base(unsigned long long n, unsigned long long base)
{
	unsigned long long		s;
	unsigned long long		tmp;
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
