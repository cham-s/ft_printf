#include "ft_printf.h"

int		is_specifier(char c)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'D' || c == 'x' || c == 'X' || 
			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'c' || c == 'C' || 
			c == 'p' || c == 'i' || c == '%' || c == ' ')
		return (1);
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

void	convert_str(char *spe, t_info *inf)
{
	char	*tmp;

	tmp = spe;
	++tmp;
	if (!*tmp)
		return ;
	if (*tmp == '%')
	{
		inf->ret += 1;
		inf->pos += 1;
		ft_strlstappend(&inf->spe, ft_strlstnew(ft_strdup("%"), inf->pos));
	}
	if (*tmp == 'd' || *tmp == 'i')
		spec_d(inf);
	else if (*tmp == 'D')
		spec_g_d(inf);
	else if (*tmp == 's')
		spec_s(inf);
	else if (*tmp == 'S')
		spec_g_s(inf);
	else if (*tmp == 'p')
		spec_p(inf);
	else if (*tmp == 'o')
		spec_o(inf);
	else if (*tmp == 'O')
		spec_g_o(inf);
	else if (*tmp == 'u')
		spec_u(inf);
	else if (*tmp == 'U')
		spec_g_u(inf);
	else if (*tmp == 'x')
		spec_x(inf);
	else if (*tmp == 'X')
		spec_g_x(inf);
	else if (*tmp == 'c')
		spec_c(inf);
	else if (*tmp == 'C')
		spec_g_c(inf);
	else if (*tmp == ' ')
		return ;
}

char	*get_special_str(char *s, t_info *i)
{
	int		j;
	char	*new;

	j = 0;
	if (is_specifier(s[j + 1]) && s[j])
		++j;

	if (s[j])
		++j;
	new  = ft_strsub(s, 0, j); 
	convert_str(new, i);
	free(new);
	return (s + j);
}
