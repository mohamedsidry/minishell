/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:39:44 by msidry            #+#    #+#             */
/*   Updated: 2025/05/17 16:43:42 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"



void *ft_strchr(void *ptr, int byte)
{
    char *charptr;
    unsigned char c;

    c = (unsigned char)byte;
    charptr = (char *)ptr;
    if (!ptr)
        return (NULL);
    while (*charptr && *charptr != c)
        charptr++;
    if (*charptr == c)
        return (charptr);
    else
        return (NULL);
}