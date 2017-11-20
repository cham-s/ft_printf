/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:12:57 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/23 19:14:15 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstdio.h"
#include "ftstring.h"
#include <unistd.h>

int		ft_putstr(char const *s)
{
	if (!s)
		return (0);
	return (write(1, s, ft_strlen(s)));
}
