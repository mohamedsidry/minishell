/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listdeletenode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:07:49 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 20:26:42 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void listdeletenode(t_list **node)
{
    t_list *tmp;
    if (!node || !(*node))
        return ;
    tmp = *node;
    free(tmp->content);
    tmp->content = NULL;
    tmp->next = NULL;
    tmp->prev = NULL;
    free(*node);
    *node = NULL;
}