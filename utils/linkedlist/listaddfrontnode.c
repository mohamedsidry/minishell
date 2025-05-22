/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listaddfrontnode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:26:20 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 18:48:44 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void listaddfrontnode(t_list **chain, t_list *node)
{
    t_list *first;

    if(!chain || !node)
        return ;
    if (!(*chain))
    {
        *chain = node;
        node->prev = NULL;
        node->next = NULL;
        return ;
    }
    first = listfindfirstnode(*chain);
    while(first->prev)
        first = first->prev;
    node->prev = NULL;
    node->next = first;
    *chain = node;
}