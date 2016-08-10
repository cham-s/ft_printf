#include "ft_printf.h"

int		is_specifier(char c)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'D' || c == 'x' || c == 'X' || 
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'c' || c == 'C' || 
		c == 'p' || c == 'i')
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

	new  = ft_strsub(s, 0, j); 
	ft_strlstappend(&i->reg, ft_strlstnew(new));
	free(new);
	i->ret += j;
	return (s + j);
}

char	*get_special_str(char *s, t_info *i)
{
	int		j;
	char	*new;

	j = 0;
	while (!is_specifier(s[j]) && s[j])
		++j;

	new  = ft_strsub(s, 0, j); 
	ft_strlstappend(&i->spe, ft_strlstnew(new));
	free(new);
	// add to ret result
	return (s + j);
}
