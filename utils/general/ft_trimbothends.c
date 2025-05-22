/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimbothends.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:44:46 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 13:47:49 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char *ft_trimbothends(const char *str, t_metachar target)
{
    char *start;
    char *end;
    char *result;
    size_t len;

    if (!str)
        return (NULL);
    if (!(*str))
        return ft_strdup(str);
    start = (char *)str;
    end = (char *)str + ft_strlen(str) - 1;        
    while (*start && start != end && ((t_metachar)(*start) == target
            && ((t_metachar)(*end) == target && *(end - 1) != BACKSLASH)))
    {
        start++;
        end--;
    }
    len = end - start;
    if (end != start)
        len++;        
    result = ft_calloc(len + 1, sizeof(char));
    if (!result)
        return (NULL);
    ft_strlcpy(result, start, len + 1);
    return (result);
}
