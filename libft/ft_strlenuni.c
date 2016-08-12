#include "libft.h"

size_t	ft_strlenuni(const unsigned int *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
