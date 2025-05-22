/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listtrimnodecontent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:15:01 by msidry            #+#    #+#             */
/*   Updated: 2025/05/17 17:13:12 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void *listtrimnodecontent(void *content)
{
    void *newcontent;

    newcontent = NULL;
    if (content)
    {
        newcontent = ft_trimspaces(content);
        free(content);
        content = NULL;
        return (newcontent);
    }
    return (newcontent);
}