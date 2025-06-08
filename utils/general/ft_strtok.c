#include "../../include/header.h"

static int	is_delimiter(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*saved = NULL;
	char		*start;

	if (str)
		saved = str;
	if (!saved)
		return (NULL);
	while (*saved && is_delimiter(*saved, delim))
		saved++;
	if (!*saved)
		return (NULL);
	start = saved;
	while (*saved && !is_delimiter(*saved, delim))
		saved++;
	if (*saved)
		*saved++ = '\0';
	return (start);
}