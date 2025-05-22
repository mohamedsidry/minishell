/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listaddbacknode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:19:26 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 18:42:10 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"


void listaddbacknode(t_list **chain, t_list *node)
{
    t_list *lastnode;
    if(!chain || !node)
        return ;
    if (!(*chain))
    {
        *chain = node;
        return ;
    }
    lastnode = listfindlastnode(*chain);
    while(lastnode->next)
        lastnode = lastnode->next;
    node->prev = lastnode;
    lastnode->next = node;
    node->next = NULL;
}