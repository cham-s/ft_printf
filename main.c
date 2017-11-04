/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 22:44:46 by cattouma          #+#    #+#             */
/*   Updated: 2017/10/31 17:14:18 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//printf
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char ch = 'h';
	char *string = "computer";
	int count = 234;
	int hex = 0x10;
	int oct = 010;
	int dec = 10;
	double fp = 251.7366;
	wchar_t wc = (wchar_t)0x0058;
	wchar_t ws[4];

	//printf("1234567890123%01234567890123456789\n\n", &count);
	/* printf("Value of count should be 13; count = %d\n\n", count); */
	/* printf("%10c%5c\n", ch, ch); */
	/* printf("%25s\n%25.4s\n\n", string, string); */
	/* printf("%f    %.2f   %e    %E\n\n", fp ,fp, fp, fp); */
	/* printf("%i    %i    %i\n\n", hex, oct, dec); */
	//printf("%0-20+#i", -10, oct, dec);
	//ft_printf("%i    %i    %i\n\n", hex, oct, dec);
	//ft_printf("Hello l this is a fmt\n", 124, 125, 126);
	//ft_printf("%-+-+-+-+-+-+-+- #015d\n", -123456789, 2, 3);
	ft_printf("% 10.4hd\n", 4);
	ft_printf("%-+ #10.4lld\n", 4);
	ft_printf("%020hd\n", 4);
}
