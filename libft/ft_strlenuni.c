#include "libft.h"

size_t	ft_strlenuni(const unsigned int* str)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		size += ft_unisize(*str);
		++str;
	}
	return (size);
}
