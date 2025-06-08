/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isredirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:00:39 by msidry            #+#    #+#             */
/*   Updated: 2025/05/29 10:01:10 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"



int ft_isredirection(unsigned char c)
{
    return (c == CHAR_REDIRECT_IN || c == CHAR_REDIRECT_OUT);
}