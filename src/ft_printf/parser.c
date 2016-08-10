#include "ft_printf.h"

int		is_specifier(char c)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'D' || c == 'x' || c == 'X' || 
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'c' || c == 'C' || 
		c == 'p' || c == 'i')
		return (1);
	return (0);
}

void	lexer(char *s, va_list pa)
{
	int i;

	i = 0;
	while (!is_specifier(s[i]))
		i++;
}
