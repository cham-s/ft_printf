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
	int ret1 = 0;
	int ret2 = 0;
	ret1 =  printf("%#X\n", INT_MAX);
	ret2 =  ft_printf("%#X\n", INT_MAX);

	printf("ret1: %d\nret2: %d\n", ret1, ret2);
}
