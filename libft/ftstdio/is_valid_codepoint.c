#include "ftstdio.h"

int	is_valid_code_point(wint_t c)
{
	if (c > 0x10ffff || (c >= 0xd800 && c <= 0xdfff)
		|| (c >= 0xe000 && c < 0xf7a0) 	
		|| (c > 0xf7a9 && c < 0xf8ff)	)
		return (-1);
	return (1);
}
