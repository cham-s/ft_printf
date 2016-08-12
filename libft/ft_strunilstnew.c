#include "libft.h"

t_str	*ft_strunilstnew(unsigned int *str)
{
	t_str		*new;
	size_t		len;

	len = ft_strlenuni(str);
	new = (t_str *)ft_memalloc(sizeof(t_str));
	if (!new || !str)
		return (NULL);
	new->str = (unsigned int *)malloc(sizeof(unsigned int) * );
	new->next = NULL;
	return (new);
}
