#include "../../include/header.h"

char *getvalue(t_list *lst, char *key)
{
    t_envnode *keyval;

    if (!lst || !key)
        return (NULL);
    while(lst)
    {
        keyval = (t_envnode *)lst->content;
        if (ft_strcmp(key, keyval->key) == 0)
            return (keyval->value);
        lst = lst->next;
    }
    return (NULL);
}

