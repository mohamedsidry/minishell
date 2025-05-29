/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismetachar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:08:36 by msidry            #+#    #+#             */
/*   Updated: 2025/05/29 11:02:00 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

size_t ft_ismetachar(unsigned char c)
{
    if (c == CHAR_PIPE || c == CHAR_REDIRECT_IN || c == CHAR_REDIRECT_OUT
        || c == CHAR_AMPERSAND || c == CHAR_SEMICOLON) // '(' AND ')' could be added here ! .
        return (1);
    return (0);
}