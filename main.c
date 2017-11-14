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

int main(void)
{
	char *l = setlocale(LC_ALL, "");
	int ret = 0;
	int ret1 = 0;
	int ret2 = 0;
	FILE *fp;

	fp = fopen("diff", "w");
	wint_t i = 0xd800;
	wchar_t s[4] = {i, i, i, 0};
/* 	printf("bool: %d\n",  i > 0x10ffff || (i >= 0xd800 && i <= 0xdfff) */
/* 		|| (i >= 0xe000 && i < 0xf7a0) */
/* 		|| (i > 0xf7a9 && i < 0xf8ff) */
/* ); */
	/* for (i = 0x000001; i < 0x10FFFF; i++) */
	/* { */
	/* 	ret1 = printf("%lc", i); */
	/* 	ret2 = ft_printf("%lc", i); */
	/* 	if (ret1 != ret2) */
	/* 		fprintf(fp, "ret1: %d\nret2: %d\ncode point: U+%X\n", ret1, ret2, i); */
	/* } */
	//assert_printf("%lc, %lc", L'暖', L'ح');
	/* ret1 = printf("%lc", s[0]); */
	/* printf("\nret1: %d\n", ret1); */
	/* ret2 = ft_printf("%lc", s[0]); */
	/* printf("\nret2: %d\n", ret2); */
}
