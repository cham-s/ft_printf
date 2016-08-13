
#include "libft.h"

unsigned int	*ft_strdupuni(const unsigned int *s1)
{
	unsigned int	*str;
	size_t			len;

	len = (ft_strlenuni(s1));
	str = (unsigned int *)malloc(sizeof(unsigned int) * len);
	if (!str)
		return (NULL);
	ft_memcpy((void *)str, s1, len);
	return (str);
}
