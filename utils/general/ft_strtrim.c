/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:47:29 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 11:33:26 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int	ft_contain(char const *regex, char c);

char	*ft_strtrim(char const *s1, char const *regex)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	if (s1 == NULL || regex == NULL)
		return (0);
	start = 0;
	while (s1[start] && ft_contain(regex, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_contain(regex, s1[end - 1]))
		end--;
	ptr = malloc(sizeof(char) * (end - start) + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, &s1[start], end - start + 1);
	return (ptr);
}

static int	ft_contain(char const *regex, char c)
{
	int	i;

	i = 0;
	while (regex[i])
	{
		if (regex[i] == c)
			return (1);
		i++;
	}
	return (0);
}