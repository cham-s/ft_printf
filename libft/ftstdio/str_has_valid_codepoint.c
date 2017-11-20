#include "ftstdio.h"

int	str_has_valid_codepoint(wchar_t * str)
{
	while(*str)
	{
		if (is_valid_code_point(*str) < 0)
			return (0);
		str++;
	}
	return (1);
}
