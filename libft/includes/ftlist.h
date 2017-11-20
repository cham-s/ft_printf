#ifndef FTLIST_H
# define FTLIST_H

# include <stdlib.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstappend(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelmem(t_list **alst, void (*del)(void **));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstinsertafter(t_list *alst, t_list *new, size_t index);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstprint(t_list **alst);
void				ft_lstremove(t_list *alst, size_t index);

#endif
