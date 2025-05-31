/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supported.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:33:17 by msidry            #+#    #+#             */
/*   Updated: 2025/05/31 15:34:58 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int unsupportedcheck(char *str);

int validsupportedmeta(t_list *token)
{
    if (!token)
        return (NONVALID);
    if (unsupportedcheck(token->content))
    {
            //TODO: display error message on stderr .
            printf("INVALID : unsupported syntax !\n");
            return (NONVALID);
    }
    return (VALID);
}


static int unsupportedcheck(char *str)
{
    return ( 1 == 0
        || !ft_strcmp(str, STR_AND)
        || !ft_strcmp(str, STR_OR)
        || !ft_strcmp(str, STR_SEMICOLON)
        || !ft_strcmp(str, STR_AMPERSAND)
        );
}