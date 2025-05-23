/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listclearnodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:25:41 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 18:49:28 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void listclearnodes(t_list **chain, void (del)(t_list **node))
{
    t_list *tmp;
    t_list *current;
    t_list *first;

    if (!chain || !(*chain))
        return ;
    first = listfindfirstnode(*chain);
    if (!first)
        return;
    current = first;
    while(current)
    {
        tmp = current->next;
        del(&current);
        current = tmp;
    }
    *chain = NULL;
}