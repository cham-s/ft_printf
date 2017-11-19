
int ft_putnstr(char *str, int n)
{
	if (str == NULL)
		return (-1);
	return (write(FT_STDOUT, str, n));
}
