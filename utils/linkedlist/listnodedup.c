#include "../../include/header.h"


t_list *listnodedup(t_list *node)
{
    t_list *newnode;

    if (!node)
        return (NULL);
    newnode = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return (NULL);

    newnode->content = ft_strdup((char *)node->content);
    if (!newnode->content)
    {
        free(newnode);
        return (NULL);
    }
    newnode->type = node->type;
    newnode->next = NULL;
    newnode->prev = NULL;
    return (newnode);
}