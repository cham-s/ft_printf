/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:45:45 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/09 01:41:51 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <limits.h>
# include <wchar.h>
# include "libft.h"
# include "dict.h"

# define NULL_LEN 6

typedef struct	s_functs_spec
{
	char	spec;
	void	(*f)(int n, int *ret);
}				t_functs_spec;

typedef struct	s_options
{
	int		has_flags;
	int		has_width;
	int		has_precision;
	int		has_length;
}				t_options;

int		ft_printf(const char *format, ...);

void	init_options(t_options *opt);

int		is_specifier(char c);

void	spec_d(va_list pa, int *ret);
void	spec_s(va_list pa, int *ret);
void	spec_g_s(va_list pa, int *ret);
void	spec_p(va_list pa, int *ret);
void	spec_c(va_list pa, int *ret);
void	spec_g_d(va_list pa, int *ret);
void	spec_o(va_list pa, int *ret);
void	spec_g_o(va_list pa, int *ret);
void	spec_u(va_list pa, int *ret);
void	spec_x(va_list pa, int *ret);
void	spec_g_x(va_list pa, int *ret);
void	spec_g_c(va_list pa, int *ret);
void	spec_g_u(va_list pa, int *ret);

#endif
