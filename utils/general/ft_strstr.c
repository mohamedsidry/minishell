/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:02:09 by msidry            #+#    #+#             */
/*   Updated: 2025/06/05 16:11:26 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char *ft_strstr(char *str1, char *str2)
{
    int i;
    i = 0;
    if (!str1 || !str2)
        return (NULL);
    while (*str1)
    {
        if (!ft_strncmp(str1, str2, ft_strlen(str2)))
            return (str1);
        str1++;
    }
    return (NULL);
}