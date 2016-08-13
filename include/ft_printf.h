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

typedef struct	s_info
{
	va_list	args;
	int			ret;
	t_str		*reg;
	t_str		*spe;
	t_str_uni	spe_uni;	
}				t_info;

typedef struct	s_options
{
	int		has_flags;
	int		has_width;
	int		has_precision;
	int		has_length;
}				t_options;

int		ft_printf(const char *format, ...);

void	init_options(t_options *opt);
void	init_info(t_info *i);

int		is_specifier(char c);
char	*get_regular_str(char *s, t_info *i);
char	*get_special_str(char *s, t_info *i);
void	convert(t_info *inf);

void	spec_d(t_info *inf);
void	spec_s(t_info *inf);
void	spec_g_s(t_info *inf);
void	spec_p(t_info *inf);
void	spec_c(t_info *inf);
void	spec_g_d(t_info *inf);
void	spec_o(t_info *inf);
void	spec_g_o(t_info *inf);
void	spec_u(t_info *inf);
void	spec_x(t_info *inf);
void	spec_g_x(t_info *inf);
void	spec_g_c(t_info *inf);
void	spec_g_u(t_info *inf);

#endif
