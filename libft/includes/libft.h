/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:57:54 by cattouma          #+#    #+#             */
/*   Updated: 2016/08/09 04:28:29 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>
# include "get_next_line.h"

typedef enum		e_bool
{
	false = 0,
	true,
}					t_bool;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strjoinfree(char *s1, char *s2);
int					ft_atoi(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
t_bool				ft_isspace(int c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(long n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_strclr(char *s);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strstr(const char *big, const char *little);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f) (unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
char				*ft_itoa_base(int n, int base);
char				*ft_uitoa_base(unsigned int value, unsigned int base);
char				*ft_ltoa_base(long long n, unsigned long long base);
char				*ft_ultoa_base(unsigned long long n, unsigned long long base);
char				*ft_stoa_base(short n, short base);
char				*ft_ustoa_base(unsigned short n, unsigned short base);
char				*ft_uctoa_base(unsigned char n, unsigned char base);
char				*ft_ctoa_base(char n, char base);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnewref(void const *content, size_t content_size);
void				ft_lstappend(t_list **alst, t_list *new);
void				ft_lstprint(t_list **alst);
size_t				ft_lstlen(t_list **lst);
void				ft_lstinsertafter(t_list *alst, t_list *new, size_t index);
void				ft_lstremove(t_list *alst, size_t index);
void				ft_lstdelmem(t_list **alst, void (*del)(void **));
char				**ft_strsplitspc(char const *s1);
char				*ft_strndup(const char *s1, size_t n);
void				*ft_memdup(const void *s1, size_t len);
size_t				ft_strlenchr(const char *s, char c);
char				*ft_arraytostr(char **str, char c);
void				ft_swap(void *a, void *b);
t_bool				ft_stronlyhas(const char *s, char c);
size_t				size_to_allocate(const char *s, char c);
char				**ft_splitspaces(char const *s);
size_t				ft_tablen(char **tab);
int 				ft_putunicode(wint_t c);
int					ft_putstruni(wchar_t *str);
void				ft_putulong(unsigned long n);
int					tabcontains(char *tabstr[], char c);

#endif
