/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 22:44:46 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/06 03:14:13 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//printf
#include <stdio.h>

int main(void)
{
	ft_printf("hello, %s\n", "world");
	printf("hello, %s\n", "world");
}
