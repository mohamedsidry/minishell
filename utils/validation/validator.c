/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:48:31 by msidry            #+#    #+#             */
/*   Updated: 2025/05/31 15:35:50 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"


void validator(t_list **tokens)
{
    if (!tokens || !*tokens
        || listvalidatenode(*tokens, validbalancedquotes) == NONVALID
        || listvalidatenode(*tokens, validsupportedmeta) == NONVALID
        || listvalidatenode(*tokens, validsyntax) == NONVALID
    )
    {
        //NOTE: removed
        // || validexpanding(*tokens, env) == NONVALID
        listclearnodes(tokens, listdeletenode);
        return ;
    }
}