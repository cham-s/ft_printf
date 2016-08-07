/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 03:07:10 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/07 03:11:01 by cattouma         ###   ########.fr       */
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

char	*ft_itoa_base(int value, int base)
{
	int i;
	int is_neg;
	int tmp;
	char *s;

	if (value == -2147483648 && base == 10)
		return ("-2147483648");
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
