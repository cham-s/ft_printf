#include "ftstdio.h"

int	ft_putstruni(wchar_t *str)
{
	int size;

	size = 0;

	while (*str)
	{
		size += ft_putunicode(*str);
		++str;
	}
	return (size);
}
