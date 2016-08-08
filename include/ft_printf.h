/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:45:45 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/08 04:14:20 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include "libft.h"

# define NULL_LEN 6

typedef struct	s_functs_spec
{
	char	spec;
	void	(*f)(int n, int *ret);
}				t_functs_spec;

int		ft_printf(const char *format, ...);
void	spec_d(va_list pa, int *ret);
void	spec_s(va_list pa, int *ret);
void	spec_p(va_list pa, int *ret);
void	spec_c(va_list pa, int *ret);
void	spec_g_d(va_list pa, int *ret);
void	spec_o(va_list pa, int *ret);
void	spec_g_o(va_list pa, int *ret);
void	spec_u(va_list pa, int *ret);
void	spec_x(va_list pa, int *ret);
void	spec_g_x(va_list pa, int *ret);

#endif
