#ifndef FTSTRING_H
# define FTSTRING_H

# define FT_STDIN	0
# define FT_STDOUT	1
# define FT_STDER	2


void		ft_bzero(void *m, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t len);
int			ft_memdel(void **ap);
void		*ft_memdup(const void *s1, size_t len);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
char		**ft_splitspaces(char const *s);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
int			ft_strequ(char const *s1, char const *s2);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoinfree(char *s1, char *s2);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *dest, const char *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strndup(const char *s1, size_t n);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnjoin(char const *s1, char const *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t n);
char		*ft_strrchr(const char *s, int c);
char		**ft_strsplit(char const *s, char c);
char		**ft_strsplitspc(char const *s);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
int			ft_strunilen(wchar_t *str);
void		ft_swap(void *a, void *b);
int			tabcontains(char *tabstr[], char c);

#endif
