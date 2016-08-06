/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 22:44:46 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/07 01:15:02 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//printf
#include <stdio.h>

int main(void)
{
	int n1, n2;

	ft_putendl("====== ft_printf ======");
	n1 = ft_printf("%s", 0);
	ft_putstr("\nret: ");
	ft_putnbr(n1);
	ft_putendl("");
	ft_putendl("====== printf ======");
	n2 = printf("%s", 0);
	ft_putstr("\nret: ");
	ft_putnbr(n2);
	ft_putendl("");
}
