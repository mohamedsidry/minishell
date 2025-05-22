/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listprintnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:14:41 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 20:21:38 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void *listprintnode(void *ptr)
{
    char *content;

    content = (char *)ptr;
    printf("content is \"%s\"\n", content);
    return (content);
}