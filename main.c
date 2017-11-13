/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 22:44:46 by cattouma          #+#    #+#             */
/*   Updated: 2017/11/11 19:29:34 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
	char *l = setlocale(LC_ALL, "");
	int ret = 0;
	int ret1 = 0;
	int ret2 = 0;
	wint_t i = 0x10fffff;
	//wint_t i = 0x1000;
	wchar_t s[4] = {i, i, i, 0}; 
	/* for (i = 0x000001; i < 0x10FFFF; i++) */
	/* { */
	/* 	ret = printf("%lc", i); */
	/* 	ret = printf("\nret: %d value: U+%X ", ret, i); */
	/* } */
	//assert_printf("%lc, %lc", L'暖', L'ح');
	ret1 = printf("%s", s);
	printf("\nret1: %d\n", ret1);
	ret2 = ft_printf("%s", s);
	printf("\nret2: %d\n", ret2);
//	printf("ret2: %d\n", ret2);
}
