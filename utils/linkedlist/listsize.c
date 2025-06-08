#include "../../include/header.h"



size_t listsize(t_list *list)
{
    size_t len;
    t_list *first;

    len = 0;
    if (!list)
        return (0);
    first = listfindfirstnode(list);
    if (!first)
        return (0);
    while (first && ++len)
        first = first->next;
    return (len);
}