/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:17:19 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/16 16:17:20 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = (ft_strlen(s1));
	str = (char *)malloc(sizeof(char) * len + 1);

	while (i < len)
	{
		str[i] = s1[i]; 
		i++;
	}
	str[i] = '\0';
	return (str);
}
