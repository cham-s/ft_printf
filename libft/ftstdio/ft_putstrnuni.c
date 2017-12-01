#include "ftstdio.h"

int	ft_putstrnuni(wchar_t *str, int n)
{
	int size;

	size = 0;
	while (n > size_bytes_code_point(*str) || n == size_bytes_code_point(*str))
	{
		size += ft_putunicode(*str);
		n -= size_bytes_code_point(*str);
		str++;
	}
	return (size);
}
