/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:09:01 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 14:39:50 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t	bytes;

	bytes = 0;
	while (*str2 && (*str1 == *str2) && (bytes < n))
	{
		str1++;
		str2++;
		bytes++;
	}
	if (bytes == n)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
