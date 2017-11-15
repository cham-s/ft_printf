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

# define NULL_LEN 6

/*
 * Flags
 * */
# define F_MINUS	0x01
# define F_PLUS		0x02
# define F_BLANK	0x04
# define F_ZERO		0x08
# define F_SHARP	0x10

/*
 * Modifiers
 * */
# define F_SH		0x01
# define F_SL		0x02
# define F_DH		0x04
# define F_DL		0x08
# define F_Z		0x10
# define F_J		0x20

/*
 * Types 
 * */
# define T_S		1
# define T_GS		2
# define T_D		3
# define T_GD		4
# define T_I		5
# define T_O		6
# define T_GO		7
# define T_U		8
# define T_GU		9
# define T_X		10
# define T_GX		11
# define T_C		12
# define T_GC		13
# define T_EE		14
# define T_FF		15
# define T_GG		16
# define T_AA		17
# define T_N		18
# define T_P		19
# define T_PNT		20	
# define T_OTH		21	

typedef struct		s_formater
{
	int				flag;
	int				width;
	int				modifier;
	int				length;
	int				type;
}					t_formater;

typedef struct	s_functs_spec
{
	char	spec;
	void	(*f)(int n, int *ret);
}				t_functs_spec;

int		ft_printf(const char *format, ...);
#endif
