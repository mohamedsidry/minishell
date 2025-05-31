/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:32:02 by msidry            #+#    #+#             */
/*   Updated: 2025/05/31 15:35:17 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int balancedquotes(char *str);

int validbalancedquotes(t_list *token)
{
    
    if (!token)
        return (NONVALID);
    if (!balancedquotes((char *)token->content))
    {
        //TODO: display error message on stderr .
        printf("INVALID : unclosed quotes !\n");
        return (NONVALID);
    }
    return (VALID);
}


static int balancedquotes(char *str)
{
    int squote;
    int dquote;
    int backtick;

    squote = 0;
    dquote = 0;
    backtick = 0;
    if (!str)
        return (0);
    while (*str)
    {
        if (*str == CHAR_SQUOTE && dquote % 2 == 0 && backtick % 2 == 0)
            squote = !squote;
        else if (*str == CHAR_DQUOTE && squote % 2 == 0 && backtick % 2 == 0)
            dquote = !dquote;
        else if (*str == CHAR_BACKTICK && squote % 2 == 0 && dquote % 2 == 0)
            backtick = !backtick;
        str++;
    }
    return (squote == 0 && dquote == 0 && backtick == 0);
}