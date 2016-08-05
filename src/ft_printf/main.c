#include <stdarg.h>
#include <unistd.h>
#include <string.h>


int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		nbr_args;
	int		ret;

	ret = 0;
	nbr_args = 0;
	char *cur_arg = format;

	if (format == NULL)
	{
		printf("(null)");
		return (6);
	}

	va_start(pa, format);

	while (*cur_arg)
	{
		if (*cur_arg == '%')
		{
			cur_arg++;
			if (*cur_arg == 'd')
			{
				printf("%d", va_arg(pa, int));
				ret += strlen(itoa(va_arg(pa, int)));
			}
			else if (*cur_arg == '%')
			{

			}
		}
		putchar(*cur_arg);
		++cur_arg;
		++ret;
	}

	va_end(pa);
}

int main()
{
	char *s = NULL;

	ft_printf("lourd ");
	return (0);
}

