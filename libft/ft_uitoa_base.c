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

#include "libft.h"

static int	conv(unsigned int n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

char	*ft_uitoa_base(unsigned int value, unsigned int base)
{
	unsigned int i;
	unsigned int tmp;
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
