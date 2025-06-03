#include "../../include/header.h"

void listclearcommands(t_list **chain, void (del)(t_command **node))
{
    t_list *tmp;
    t_list *current;
    t_list *first;

    if (!chain || !(*chain))
        return ;
    first = listfindfirstnode(*chain);
    if (!first)
        return;
    current = first;
    while(current)
    {
        tmp = current->next;
        del((t_command **)&current->content);        
        current = tmp;
    }
    *chain = NULL;
}