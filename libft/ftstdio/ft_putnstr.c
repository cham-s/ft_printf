#include "ftstdio.h"
#include <unistd.h>

int ft_putnstr(char *str, int n)
{
	if (str == NULL)
		return (-1);
	return (write(1, str, n));
}
