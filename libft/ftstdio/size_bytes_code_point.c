#include "ftstdio.h"

int			size_bytes_code_point(wint_t c)
{
	if (is_valid_code_point(c) < 0)
		return (-1);
	if (c <= 0x7f)
		return (1);
	else if (c <= 0x7ff)
		return (2);
	else if (c <= 0xffff)
		return (3);
	else if (c <= 0x10ffff)
		return (4);
	return (-1);
}
