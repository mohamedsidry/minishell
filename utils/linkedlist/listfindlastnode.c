/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfindlastnode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:31:18 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 15:31:47 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"


t_list *listfindlastnode(t_list *list)
{
    if (!list)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}