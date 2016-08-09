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

#include "libft.h"

static long long	conv(unsigned long long n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

char	*ft_ultoa_base(unsigned long long value, unsigned long long base)
{
	unsigned long long i;
	unsigned long long tmp;
	char *s;

	tmp = value;
	i = 0;
	while (tmp >= base)
	{
		tmp /= base;
		i++;
	}
	s = (char *)malloc(sizeof(char) * i + 1);
	s[i + 1] = '\0';
	while (i != 0)
	{
		tmp = value % base;
		s[i] = conv(tmp);
		value /= base;
		i--;
	}
	return (s);
}
