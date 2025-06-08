/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stripspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:17:38 by msidry            #+#    #+#             */
/*   Updated: 2025/05/17 17:11:39 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

//NOTE: this is broken !?????
char *ft_stripspace(const char *str)
{
    const char *start;
    const char *end;
    char *result;
    size_t len;

    if (!str)
        return (NULL);
    start = str;
    while (*start && ft_isspace(*start))
        start++;
    if (!(*start))
        return ft_strdup(start);
    end = start + ft_strlen(start) ;
    while (end > start && ft_isspace(*(end - 1)))
        end--;
    if (end == start)
        return (ft_strdup(""));
    len = end - start;
    result = ft_calloc(len + 1, sizeof(char));
    if (!result)
        return (NULL);
    ft_strlcpy(result, start, len + 1);
    return (result);
}
