#include "libft.h"

int ft_putnstr(char *str, int n)
{
	int ret;

	ret = 0;

	if (str == NULL)
		return -1;
	return (write(1, str, n));
}
