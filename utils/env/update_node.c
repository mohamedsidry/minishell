/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:20:01 by msidry            #+#    #+#             */
/*   Updated: 2025/06/05 17:27:36 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

t_envnode *update_node(t_list **envlst, char *key, char *value)
{
    t_envnode *node;
    char *checkexist;
    char *tmp;
    
    if (!envlst || !key || !value)
        return (NULL);
    checkexist = getvalue(*envlst, key);
    if (checkexist)
    {
        setvalue(*envlst, key, ft_strdup(value));
        return ((t_envnode *)(checkexist - 8)); //NOTE: do not try to understand ! *(-_-)*
    }
    tmp = ft_concatenate(key, value, "=");
    node = create_node(tmp);
    free(tmp);
    listaddbacknode(envlst, listcreatenode(node));
    return (node);
}
