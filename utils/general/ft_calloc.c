/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:55:13 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 14:40:12 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"


void *ft_calloc(size_t count, size_t size)
{
    size_t total;
    size_t idx;
    char *ptr;
    void *memo;

    total = count * size;
    if (total <= 0)
        return (NULL);
    memo = (void *)malloc(total);
    if (!memo)
        return (NULL);
    idx = 0;
    ptr = (char *)memo;
    while (idx < total)
    {
        *ptr = '\0';
        ptr++;
        idx++;
    }
    return (memo);
}
