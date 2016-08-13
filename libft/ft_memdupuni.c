#include "libft.h"

void	*ft_memdupuni(void *s1, size_t len)
{
	unsigned int	*s;
	unsigned int	*t;
	size_t			i;

	t = (unsigned int *)s1;
	i = 0;
	s = (unsigned int*)malloc(sizeof(unsigned int) * len + 1);
	if (!s)
		return (NULL);
	while (len--)
	{
		s[i] = t[i];
		++i;
	}
	s[i] = 0;
	return (s);
}
