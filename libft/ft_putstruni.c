#include "libft.h"

int	ft_putstruni(const unsigned int* str)
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
