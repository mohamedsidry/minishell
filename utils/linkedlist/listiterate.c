/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listiterate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:13:39 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 18:50:29 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

t_list *listiterate(t_list *listhead, void *(fun)(void *))
{
    t_list *tmp;

    tmp = listhead;
    if (!listhead || !fun)
        return (NULL);
    while(tmp)
    {
        tmp->content = fun(tmp->content);
        if (!tmp->content)
            return (NULL);
        tmp = tmp->next;
    }
    return (listhead);
}
