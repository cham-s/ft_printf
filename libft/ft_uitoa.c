/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 04:24:02 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/09 04:34:27 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int		ft_size(unsigned int n)
{
	unsigned int		s;

	s = 0;
	while (n)
	{
		s++;
		n /= 10;
	}
	return (s);
}

char			*ft_uitoa(unsigned int n)
{
	unsigned int		s;
	unsigned int		t;
	char	*new;

	if (!n)
		s = 1;
	else
		s = ft_size(n);
	t = n;
	if (!(new = ft_strnew(s)))
		return (NULL);
	while (s--)
	{
		new[s] = (n % 10) + '0';
		n /= 10;
	}
	return (new);
}
