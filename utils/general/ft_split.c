#include "../../include/header.h"

static int	check_inword(char const *s, char c)
{
	int	counter;
	int	inword;

	inword = 0;
	counter = 0;
	while (*s)
	{
		if (*s == c)
			inword = 0;
		else if (!inword)
		{
			inword = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

static char	*writer(char const *s, char sep)
{
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != sep && s[i])
		i++;
	result = (char *)malloc(i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] != sep && s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	*free_split(char **split, int i)
{
	i--;
	while (i >= 0)
		free(split[i--]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = check_inword(s, c);
	i = 0;
	split = (char **)malloc(sizeof(char *) * (len + 1));
	if (!split)
		return (NULL);
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		split[i] = writer(s, c);
		if (!split[i])
			return (free_split(split, i));
		while (*s && *s != c)
			s++;
		i++;
	}
	split[i] = NULL;
	return (split);
}