#include "ftstdio.h"
#include <unistd.h>

size_t	ft_putnstr(char *str, int n)
{
	if (str == NULL)
		return (0);
	return (write(1, str, n));
}
