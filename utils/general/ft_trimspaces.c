#include "../../include/header.h"


char *ft_trimspaces(const char *str)
{
	char *trimed;
	char *end;
	char *start;
	int len;

	start = (char *)str;
	if (!str)
		return (NULL);
	while (start && ft_isspace(*start))
		start++;
	end = start + ft_strlen(start);
	while (end > start && ft_isspace(*(end - 1)))
		end--;
	if (end <= start)
		return (ft_strdup(""));
	len = (end - start) + 1;
	trimed = malloc(sizeof(char) * len);
	if (!trimed)
		return (NULL);
	ft_strlcpy(trimed, start, len);
	printf("trimed is '%s'\n", trimed);
	return (trimed);
}
