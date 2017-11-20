/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 02:28:26 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/09 02:51:50 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstdio.h"
#include "ftstring.h"

static unsigned int	conv(unsigned int n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

static	unsigned int		ft_size(unsigned int n, unsigned int base)
{
	unsigned int		s;

	s = 0;
	while (n)
	{
		s++;
		n /= base;
	}
	return (s);
}

char			*ft_uitoa_base(unsigned int n, unsigned int base)
{
	unsigned int		s;
	unsigned int		tmp;
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
