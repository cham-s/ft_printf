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

# define NULL_LEN 6

# include <wchar.h>
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
# define F_SH		1
# define F_SL		2
# define F_DH		3
# define F_DL		4
# define F_Z		5
# define F_J		6

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
	int				precision;
	int				length;
	int				type;
}					t_formater;

typedef struct		s_printf
{
	int				ret;
	int				fmt_err;
	char			*prefix;
	const char		*str;
	wchar_t			*w_str;
	char			*fmt_str;
	char			invalid;
}					t_printf;

typedef struct		s_functs_spec
{
	char			spec;
	void			(*f)(int n, int *ret);
}					t_functs_spec;

int					ft_printf(const char *format, ...);

/*
 *  Init functions.
 */
void				init_formater(t_formater *fmt);
void				init_printf(t_printf *pf, const char *format);

/*
 * Utilities functions.
 */
int 				is_neg(char *str);
int 				is_signed(t_formater *fmt);
int					final_size(int a, int b);
int					print_n_char(char c, int size);
char				*str_tolower(char *str);
int					is_type(char c);
int					is_flag(char c);
int 				is_modifier(char c);

/*
 * Formatting printing functions.
 */
int					print_with_precision(t_formater *fmt, t_printf *pf);
int					print_regular(t_formater *fmt, t_printf *pf);
int					printable_size(wchar_t *str, int n);
int					print_str_precision(t_formater *fmt, t_printf *pf);
int					print_str_regular(t_formater *fmt, t_printf *pf);
int					print_padding_str(t_formater *fmt, int size);

/*
 * Format handler function.
 */
void				handle_format_string(t_printf *pf, va_list *pa);
void				set_flags(t_formater *fmt, t_printf *pf);
void				set_width(t_formater *fmt, t_printf *pf, va_list *pa);
void				set_precision_length(t_formater *fmt, t_printf *pf, va_list *pa);
void				set_modifier(t_formater *fmt, t_printf *pf);
void				set_type(t_formater *fmt, t_printf *pf);
void				set_formater(t_formater *fmt, t_printf *pf, va_list *pa);

/*
 *  Formater functions
 */
void				format_str(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_gstr(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_d(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_gd(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_p(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_c(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_gc(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_o(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_go(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_x(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_gx(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_u(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_gu(t_printf *pf, va_list *pa, t_formater *fmt);
void				format_oth(t_printf *pf, va_list *pa, t_formater *fmt);

#endif
