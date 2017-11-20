#include "ftstdio.h"

static int	one_byte_sequence(wint_t c)
{
	ft_putchar(c);
	return (1);
}

static int	two_bytes_sequence(wint_t c)
{
	ft_putchar(0xc0 | (c >> 6));
	ft_putchar(0x80 | (c & 0x3f));
	return(2);
}

static int	three_bytes_sequence(wint_t c)
{
	ft_putchar(0xe0 | (c >> 12));
	ft_putchar(0x80 | ((c >> 6) & 0x3f));
	ft_putchar(0x80 | (c & 0x3f));
	return(3);
}

static int	four_bytes_sequence(wint_t c)
{
	ft_putchar(0xf0 |  (c >> 18));
	ft_putchar(0x80 | ((c >> 12) & 0x3f));
	ft_putchar(0x80 | ((c >> 6) & 0x3f));
	ft_putchar(0x80 | (c & 0x3f));
	return(4);
}
int	ft_putunicode(wint_t c)
{
	if (is_valid_code_point(c) < 0)
		return (-1);
	if (c <= 0x7f)
		return (one_byte_sequence(c));
	else if (c <= 0x7ff)
		return (two_bytes_sequence(c));
	else if (c <= 0xffff)
		return (three_bytes_sequence(c));
	else if (c <= 0x10ffff)
		return (four_bytes_sequence(c));
	return (-1);
}
