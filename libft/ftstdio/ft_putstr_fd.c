/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:15:45 by cattouma          #+#    #+#             */
/*   Updated: 2015/11/27 18:01:12 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstdio.h"
#include "ftstring.h"
#include <unistd.h>

int		ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return (-1);
	return (write(fd, s, ft_strlen(s)));
}
