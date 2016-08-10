#include "libft.h"

void	ft_strlstappend(t_str **list, t_str *new)
{
	t_str *current;

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
