/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:48:31 by msidry            #+#    #+#             */
/*   Updated: 2025/05/29 15:23:27 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int validbalancedquotes(t_list *token);
int balancedquotes(char *str);
int validsupportedmeta(t_list *token);
int unsupportedcheck(char *str);

void validator(t_list **tokens)
{
    if (!tokens || !*tokens)
        return ;
    if(!validbalancedquotes(*tokens))
    {
        printf("INVALID : unclosed quotes !\n");
        listclearnodes(tokens, listdeletenode);
    }
    if (!validsupportedmeta(*tokens))
    {
        printf("INVALID : unsupported syntax !\n");
        listclearnodes(tokens, listdeletenode);
    }
}

int validbalancedquotes(t_list *token)
{
    if (!token)
        return (0);
    while (token)
    {
        if (!balancedquotes(token->content))
            return (0);
        token = token->next;
    }
    return (1);
}


int balancedquotes(char *str)
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
        if (*str == CHAR_SQUOTE)
            squote++;
        else if (*str == CHAR_DQUOTE)
            dquote++;
        else if (*str == CHAR_BACKTICK)
            backtick++;
        str++;
    }
    return (squote % 2 == 0 && dquote % 2 == 0 && backtick % 2 == 0);
}

int validsupportedmeta(t_list *token)
{
    if (!token)
        return (0);
    while (token)
    {
        if (unsupportedcheck(token->content))
            return (0);
        token = token->next;
    }
    return (1);
}


int unsupportedcheck(char *str)
{
    return (!ft_strcmp(str, STR_AND) || !ft_strcmp(str, STR_OR));
}