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

	inf->pos += 1;
	n = va_arg(inf->args, int);
	buffer = ft_itoa(n);
	inf->ret += ft_strlen(buffer);
	ft_strlstappend(&inf->spe, ft_strlstnew(buffer, inf->pos));
	free(buffer);
}

void	spec_g_d(t_info *inf)
{
	long long	n;
	char		*buffer;

	inf->pos += 1;
	n = va_arg(inf->args, long long);
	buffer = ft_ltoa_base(n, 10);
	inf->ret += ft_strlen(buffer);
	ft_strlstappend(&inf->spe, ft_strlstnew(buffer, inf->pos));
	free(buffer);
}

void	spec_o(t_info *inf)
{
	char	*s;

	inf->pos += 1;
	s = ft_itoa_base(va_arg(inf->args, unsigned int), 8);
	ft_strlstappend(&inf->spe, ft_strlstnew(s, inf->pos));
	inf->ret += ft_strlen(s);
	free(s);
}

void	spec_g_o(t_info *inf)
{
	char *s;

	inf->pos += 1;
	s = ft_ltoa_base(va_arg(inf->args, unsigned long), 8);
	ft_strlstappend(&inf->spe, ft_strlstnew(s, inf->pos));
	inf->ret += ft_strlen(s);
	free(s);
}

void	spec_u(t_info *inf)
{
	unsigned int	n;
	char			*buffer;

	inf->pos += 1;
	n = va_arg(inf->args, unsigned int);
	buffer = ft_uitoa(n);
	inf->ret += ft_strlen(ft_uitoa(n));
	ft_strlstappend(&inf->spe, ft_strlstnew(buffer, inf->pos));
	free(buffer);
}

void	spec_g_u(t_info *inf)
{
	unsigned long	n;
	char			*buffer;

	inf->pos += 1;
	n = va_arg(inf->args, unsigned long);
	buffer = ft_ultoa_base(n, 10);
	ft_strlstappend(&inf->spe, ft_strlstnew(buffer, inf->pos));
	inf->ret += ft_strlen(buffer);
	free(buffer);
}

void	spec_c(t_info *inf)
{
	int c;

	inf->pos += 1;
	c = va_arg(inf->args, int);
	ft_strlstappend(&inf->spe, ft_strlstnew((char *)&c, inf->pos));
	inf->ret += 1;
}

void	spec_g_c(t_info *inf)
{
	unsigned int	c;
	int				size;

	inf->pos += 1;
	c = va_arg(inf->args, unsigned int);
	size = ft_unisize(c);
	ft_strlstappenduni(&inf->spe_uni, ft_strunilstnew((unsigned int *)&c, inf->pos));
	inf->ret += size;
}

void	spec_s(t_info *inf)
{
	char	*s;
	char	*buffer;

	inf->pos += 1;
	s = va_arg(inf->args, char*);
	if (!s)
	{
		buffer = ft_strdup("(null)");
		inf->ret += NULL_LEN;
		ft_strlstappend(&inf->spe, ft_strlstnew(buffer, inf->pos));
		free(buffer);
		inf->pos += 1;
		inf->spe->pos = inf->pos;
		return ;
	}
	buffer = ft_strdup(s);
	ft_strlstappend(&inf->spe, ft_strlstnew(buffer, inf->pos));
	inf->ret += ft_strlen(s);
}
/*  */
void	spec_g_s(t_info *inf)
{
	unsigned int	*s;
	unsigned int	*buffer;
	int				size;

	inf->pos += 1;
	s = va_arg(inf->args, unsigned int*);
	if (!s)
	{
		buffer = ft_memdupuni(L"(null)", NULL_LEN);
		ft_strlstappenduni(&inf->spe_uni, ft_strunilstnew(buffer, inf->pos));
		inf->ret += NULL_LEN;
		free(buffer);
		return ;
	}
	buffer = ft_memdupuni(s, ft_strlenuni(s));
	size = ft_strbytelen(s);
	ft_strlstappenduni(&inf->spe_uni, ft_strunilstnew(s, inf->pos));
	inf->ret += size;
	free(buffer);
}

void	spec_p(t_info *inf)
{
	void				*n;
	unsigned long long	addr;
	char				*output;
	char				*s;

	inf->pos += 1;
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
	ft_strlstappend(&inf->spe, ft_strlstnew(s, inf->pos));
	free(output);
	free(s);
}

void	spec_x(t_info *inf)
{
	char *s;
	char *output;

	inf->pos += 1;
	output = ft_uitoa_base(va_arg(inf->args, unsigned int), 16);
	s = output;
	while (*s)
	{
		*s = ft_tolower(*s);
		s++;
	}
	ft_strlstappend(&inf->spe, ft_strlstnew(output, inf->pos));
	inf->ret += ft_strlen(output);
}

void	spec_g_x(t_info *inf)
{
	char *output;

	inf->pos += 1;
	output = ft_ltoa_base(va_arg(inf->args, unsigned int), 16);
	ft_strlstappend(&inf->spe, ft_strlstnew(output, inf->pos));
	inf->ret += ft_strlen(output);
}
