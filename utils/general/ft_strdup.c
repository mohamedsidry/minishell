/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:30:23 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 14:40:08 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"



char *ft_strdup(const char *str)
{
    size_t len;
    char *ptr;

    if (!str)
        return (NULL);
    len = ft_strlen(str);
    ptr = ft_calloc(len + 1, sizeof(char));    
    if (!ptr)
        return (NULL);
    ft_strlcpy(ptr, str, len + 1);
    return (ptr);
}
