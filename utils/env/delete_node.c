#include "../../include/header.h"

void delete_node(t_list **node)
{
    t_envnode *envcontent;
    t_list *tmp;

    if (!node || !(*node))
        return ;
    tmp = *node;
    envcontent = (t_envnode *)tmp->content;
    if (envcontent)
    {
        free (envcontent->key);
        free (envcontent->value);
        envcontent->key = NULL;
        envcontent->value = NULL;
        listdeletenode(node);
    }
}