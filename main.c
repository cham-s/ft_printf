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

// KO
//ret1 =  printf("%C", (wint_t) - 2); 
	//ret1 = printf("%C\n", 0xe000);

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
	ret1 =  printf("{% 02d}\n", 0); 
	//ret2 =  ft_printf("{% 04d}\n", 0); 
	printf("ret1: %d\nret2: %d\n", ret1, ret2);
}
