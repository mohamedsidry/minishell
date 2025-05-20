
int ft_strcmp(char *str1, char *str2)
{
	if (str1 == str2)
		return (0);

	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}
