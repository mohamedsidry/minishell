/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfindfirstnode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:28:21 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 15:32:10 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"


t_list *listfindfirstnode(t_list *list)
{
    if (!list)
        return (NULL);
    while (list->prev)
        list = list->prev;
    return (list);
}