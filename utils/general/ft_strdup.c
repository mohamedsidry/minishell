#include "../../include/header.h"

char *ft_strdup(const char *str)
{
	char *newstr;
	size_t len;

	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	
	newstr = (char *)malloc(sizeof(char) * len);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, str, len);
	return (newstr);
}
