#include "ft_printf.h"

int		is_specifier(char c)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'D' || c == 'x' || c == 'X' || 
			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'c' || c == 'C' || 
			c == 'p' || c == 'i' || c == '%' || c == ' ')
		return (c);
	return (0);
}

char	*get_regular_str(char *s, t_info *i)
{
	int		j;
	char	*new;

	j = 0;
	while (s[j] != '%' && s[j])
		++j;

	i->pos += 1;
	new  = ft_strsub(s, 0, j); 
	ft_strlstappend(&i->reg, ft_strlstnew(new, i->pos));
	free(new);
	i->ret += j;
	return (s + j);
}

void	choose_specifier(char spec, t_info *inf)
{
	if (spec == '%')
	{
		inf->ret += 1;
		inf->pos += 1;
		ft_strlstappend(&inf->spe, ft_strlstnew(ft_strdup("%"), inf->pos));
	}
	else if (spec == 'd' || spec == 'i')
		spec_d(inf);
	else if (spec == 'D')
		spec_g_d(inf);
	else if (spec == 's')
		spec_s(inf);
	else if (spec == 'S')
		spec_g_s(inf);
	else if (spec == 'p')
		spec_p(inf);
	else if (spec == 'o')
		spec_o(inf);
	else if (spec == 'O')
		spec_g_o(inf);
	else if (spec == 'u')
		spec_u(inf);
	else if (spec == 'U')
		spec_g_u(inf);
	else if (spec == 'x')
		spec_x(inf);
	else if (spec == 'X')
		spec_g_x(inf);
	else if (spec == 'c')
		spec_c(inf);
	else if (spec == 'C')
		spec_g_c(inf);
	else if (spec == ' ')
		return ;
}

// possible leaks
void	check_format(char *spe, t_info *inf)
{
	char 		*tmp;

	tmp = spe;
	++tmp;
	while (*tmp)
	{
		if (*tmp == '-')
			inf->options.flag.minus = 1;
		else if (*tmp == '+')
			inf->options.flag.plus = 1;
		else if (*tmp == ' ')
			inf->options.flag.space = 1;
		else if (*tmp == '#')
			inf->options.flag.sharp = 1;
	}
}

void	convert_str(char *spe, t_info *inf)
{
	char	*tmp;

	tmp = spe;
	//++tmp;
	if (!*tmp)
		return ;
	if (is_specifier(*tmp))
		choose_specifier(*tmp, inf);
	else
		check_format(spe, inf);
}

char	*get_special_str(char *s, t_info *i)
{
	int		j;
	char	*new;

	j = 1;
	while (!is_specifier(s[j]) && s[j])
		++j;
	++j;
	new  = ft_strsub(s, 1, j); 
	convert_str(new, i);
	free(new);
	return (s + j);
}
