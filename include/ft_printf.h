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

typedef struct	s_flag
{
	int	minus;
	int plus;
	int space;
	int sharp;
}				t_flag;

typedef struct	s_width
{
	int n;
	int	n_zero;
}				t_width;

typedef struct	s_prec
{
	int	pres_num;
}				t_prec;

typedef struct	s_length
{
	int	hh;
	int	h;
	int	l;
	int	ll;
	int	z;
}				t_length;
typedef struct	s_options
{
	t_length	length;
	t_prec		prec;
	t_width		width;
	t_flag		flag;
}				t_options;

typedef struct	s_info
{
	va_list	args;
	int			ret;
	t_str		*reg;
	t_str		*spe;
	t_str_uni	*spe_uni;	
	int			pos;
	t_options	options;
}				t_info;


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
