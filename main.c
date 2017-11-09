/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 22:44:46 by cattouma          #+#    #+#             */
/*   Updated: 2017/11/07 02:22:48 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned long l;
	int ret = 0;
	int ret2 = 0;
	char values[4] = {0, 0, 0, 0};
	unsigned int ch = (unsigned int)L'ψ'; 
	//ret = ft_printf("{% %}");
	//ret2 = ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	//ret2 = printf("{% 2%}");
	//printf("return: %d\n", ret);
	printf("%lc\n", L'ψ');	
	ft_printf("%C", L'猫');
	/* printf("%C", L'δ'); */
	/* printf("%C", L'요'); */
	/* printf("%C", L'莨'); */
	/* printf("%C", L'ي'); */
}
