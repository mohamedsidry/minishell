/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listcreatenode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:52:26 by msidry            #+#    #+#             */
/*   Updated: 2025/05/16 19:32:26 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

t_list *listcreatenode(void *content)
{
    t_list *node;

    node = ft_calloc(1, sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;
    return (node);
}