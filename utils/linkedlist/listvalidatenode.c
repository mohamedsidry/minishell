/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listvalidatenode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:47:45 by msidry            #+#    #+#             */
/*   Updated: 2025/05/31 15:18:20 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int listvalidatenode(t_list *head, int (*valid)(t_list *node))
{
    t_list *tmp;

    tmp = head;
    if (!head || !valid)
        return (VALID);
    while(tmp)
    {
        if(valid(tmp) == NONVALID)
            return (NONVALID);
        tmp = tmp->next;
    }
    return (VALID);
}