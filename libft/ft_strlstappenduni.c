#include "libft.h"

void	ft_strlstappenduni(t_str_uni **list, t_str_uni *new)
{
	t_str_uni *current;

	current = *list;
	if (current == NULL)
		*list = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}
