#include "../../include/header.h"

void setvalue(t_list *lst, char *key, char *newvalue)
{
    t_envnode *keyval;

    if (!lst)
        return ;
    while (lst)
    {
        keyval = (t_envnode *)lst->content;
        if (ft_strcmp(key, keyval->key))
        {
            nullstr(&keyval->value);
            keyval->value = newvalue;
            return ;
        }
        lst = lst->next;
    } 
}