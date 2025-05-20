#include "../../include/header.h"


size_t ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t count;

	count = 0;

	if (!dst || !src)
		return (ft_strlen(src));

	if (n > 0)
	{
		while ((count < n - 1) && src[count])
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (ft_strlen(src));
}
