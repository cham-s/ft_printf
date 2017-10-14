
#include "libft.h"

int		tabcontains(char *tabstr[], char c)
{
	int i;
	int first_char;

	i = 0;
	first_char = 0;
	while (tabstr[i])
	{
		if (tabstr[i][first_char] == c)
			return 1;
		i += 1;
	}
	return (0);
}
