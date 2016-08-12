#include "libft.h"

int		ft_unisize(const unsigned int cu)
{
	if (cu < 128)
		return (1);
	else if (cu < 2048)
		return(2);
	else if (cu < 65536)
		return(3);
	else if (cu < 1114112)
		return(4);
	return (0);
}
