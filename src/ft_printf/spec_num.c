/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 23:14:37 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/09 04:28:45 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_d(t_info *inf)
{
	int		n;
	char	*buffer;

	n = va_arg(inf->args, int);
	buffer = ft_itoa(n);
	inf->ret += ft_strlen(buffer);
	ft_strlstappend(&inf->spe, ft_strlstnew(buffer));
	free(buffer);
}

/* void	spec_u(t_info *inf) */
/* { */
/* 	unsigned int n; */
/*  */
/* 	n = va_arg(pa, unsigned int); */
/* 	ft_putnbr(n); */
/* 	*ret += ft_strlen(ft_uitoa(n)); */
/* } */
/*  */
/* void	spec_g_u(t_info *inf) */
/* { */
/* 	unsigned long n; */
/*  */
/* 	n = va_arg(pa, unsigned long); */
/* 	ft_putulong(n); */
/* 	*ret += ft_strlen(ft_ultoa_base(n, 10)); */
/* } */
/*  */
/* void	spec_g_d(t_info *inf) */
/* { */
/* 	long long n; */
/*  */
/* 	n = va_arg(pa, long long); */
/* 	ft_putnbr(n); */
/* 	*ret += ft_strlen(ft_ltoa_base(n, 10)); */
/* } */
/*  */
/* void	spec_c(t_info *inf) */
/* { */
/* 	wchar_t c; */
/*  */
/* 	c = va_arg(pa, wchar_t); */
/* 	ft_putchar(c); */
/* 	*ret += 1; */
/* } */
/*  */
/* void	spec_g_c(t_info *inf) */
/* { */
/* 	unsigned int	c; */
/* 	int				size; */
/*  */
/* 	c = va_arg(pa, unsigned int); */
/* 	size = ft_putunicode(c); */
/* 	*ret += size; */
/* } */
/*  */
/* void	spec_o(t_info *inf) */
/* { */
/* 	char *s; */
/*  */
/* 	s = ft_itoa_base(va_arg(pa, unsigned int), 8); */
/* 	ft_putstr(s); */
/* 	*ret += ft_strlen(s); */
/* } */
/*  */
/* void	spec_g_o(t_info *inf) */
/* { */
/* 	char *s; */
/*  */
/* 	s = ft_ltoa_base(va_arg(pa, unsigned long), 8); */
/* 	ft_putstr(s); */
/* 	*ret += ft_strlen(s); */
/* } */
/*  */
void	spec_s(t_info *inf)
{
	char	*s;
	char	*buffer;

	s = va_arg(inf->args, char*);
	if (!s)
	{
		buffer = ft_strdup("(null)");
		inf->ret += NULL_LEN;
		ft_strlstappend(&inf->spe, ft_strlstnew(buffer));
		free(buffer);
		return ;
	}
	buffer = ft_strdup(s);
	ft_strlstappend(&inf->spe, ft_strlstnew(buffer));
	inf->ret += ft_strlen(s);
}
/*  */
/* void	spec_g_s(t_info *inf) */
/* { */
/* 	unsigned int	*s; */
/* 	int				size; */
/*  */
/* 	s = va_arg(inf->args, unsigned int*); */
/* 	if (!s) */
/* 	{ */
/* 		ft_strlstappend(&inf->spe, ft_strlstnew("(null)")); */
/* 		*ret += NULL_LEN; */
/* 		return ; */
/* 	} */
/* 	size = ft_putstruni(s); */
/* 	*ret += size; */
/* } */
/*  */
void	spec_p(t_info *inf)
{
	void				*n;
	unsigned long long	addr;
	char				*output;
	char				*s;

	n = va_arg(inf->args, void*);
	addr = (unsigned long long)n;
	output = ft_ltoa_base(addr, 16);
	s = output;
	while (*s)
	{
		*s = ft_tolower(*s);
		s++;
	}
	s = ft_strjoin("0x", output);
	inf->ret += ft_strlen(s);
	ft_strlstappend(&inf->spe, ft_strlstnew(s));
	free(output);
	free(s);
}
/*  */
/* void	spec_x(t_info *inf) */
/* { */
/* 	char *s; */
/* 	char *output; */
/*  */
/* 	output = ft_uitoa_base(va_arg(pa, unsigned int), 16); */
/* 	s = output; */
/* 	while (*s) */
/* 	{ */
/* 		*s = ft_tolower(*s); */
/* 		s++; */
/* 	} */
/* 	ft_putstr(output); */
/* 	*ret += ft_strlen(output); */
/* } */
/*  */
/* void	spec_g_x(t_info *inf) */
/* { */
/* 	char *output; */
/*  */
/* 	output = ft_ltoa_base(va_arg(pa, unsigned int), 16); */
/* 	ft_putstr(output); */
/* 	*ret += ft_strlen(output); */
/* } */
