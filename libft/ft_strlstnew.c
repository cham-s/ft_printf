#include "libft.h"

t_str	*ft_strlstnew(char *str, int position)
{
	t_str		*new;

	new = (t_str *)ft_memalloc(sizeof(t_str));
	if (!new || !str)
		return (NULL);
	new->str = ft_strdup(str);
	new->next = NULL;
	new->pos = position;
	return (new);
}
