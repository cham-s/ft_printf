#ifndef FTSTDIO_H
# define FTSTDIO_H

# include <wchar.h> 
# define BUFF_SIZE 64

typedef struct		s_file
{
	int				fd;
	char			*buffer;
	struct s_file	*right;
	struct s_file	*left;
}					t_file;

int			get_next_line(int const fd, char **line);
int			ft_atoi(const char *str);
char		*ft_ctoa_base(char n, char base);
char		*ft_itoa(int n);
char		*ft_itoa_base(int n, int base);
char		*ft_ltoa_base(long long value, unsigned long long base);
int			ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr(long n);
void		ft_putnbr_fd(int n, int fd);
int			ft_putnstr(char *str, int n);
int			ft_putstr(char const *s);
int			ft_putstr_fd(char const *s, int fd);
int			ft_putstruni(wchar_t *str);
void		ft_putulong(unsigned long n);
int			ft_putunicode(wint_t c);
char		*ft_stoa_base(short n, short base);
char		*ft_uctoa_base(unsigned char n, unsigned char base);
char		*ft_uitoa(unsigned int n);
char		*ft_uitoa_base(unsigned int n, unsigned int base);
char		*ft_ultoa_base(unsigned long long n, unsigned long long base);
char		*ft_ustoa_base(unsigned short n, unsigned short base);
int			get_next_line(int const fd, char **line);
int			is_valid_code_point(wint_t c);
int			size_bytes_code_point(wint_t c);
int			str_has_valid_codepoint(wchar_t * str);

#endif
