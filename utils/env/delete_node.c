#include "../../include/header.h"

void delete_node(t_list *node)
{
    t_envnode *envcontent;

    if (!node)
        return ;

    envcontent = node->content;
    if (envcontent)
    {
        free (envcontent->key);
        free (envcontent->value);
        envcontent->key = NULL;
        envcontent->value = NULL;

    }
    listdeletenode(node);
}