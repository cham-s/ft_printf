#include "ftstring.h" 

size_t	ft_strunilen(wchar_t *str)
{
	int size;

	if (str == NULL)
		return (0);
	size = 0;
	while (*str)
	{
		size += size_bytes_code_point(*str);
		++str;
	}
	return (size);
}
