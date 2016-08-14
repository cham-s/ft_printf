#include "libft.h"

t_str_uni	*ft_strunilstnew(unsigned int *str, int position)
{
	t_str_uni	*new;
	size_t		len;

	len = ft_strlenuni(str);
	new = (t_str_uni *)ft_memalloc(sizeof(t_str_uni));
	if (!new || !str)
		return (NULL);
	new->str = ft_memdupuni(str, len);
	new->next = NULL;
	new->pos = position;
	return (new);
}
