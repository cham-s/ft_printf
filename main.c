/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 22:44:46 by cattouma          #+#    #+#             */
/*   Updated: 2017/11/14 22:04:40 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
	char *l = setlocale(LC_ALL, "");
	wchar_t s[5] = {0x200, 0x200, 0x200, 0x200, 0x0};
	int ret1 = 0;
	int ret2 = 0;
	/* ret1 = printf("{%05s}", "abc"); */
	/* ret2 = ft_printf("{%05s}", "abc"); */
	ret1 = printf("{%#.6X}", 4);
	//ret2 = ft_printf("{% 03d}", 0);
	printf("\nret1: %d\nret2: %d\n", ret1, ret2);
}
