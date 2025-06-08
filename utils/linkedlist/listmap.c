#include "../../include/header.h"



t_list *listmap(t_list *head, t_list *(fun)(t_list *node))
{
    t_list *newlist;
    t_list *newnode;


    newlist = NULL;

    if (!head || !fun)
        return (NULL);

    while (head)
    {
        newnode = fun(head);
        if (!newnode)
        {
            listclearnodes(&newlist, listdeletenode);
            return (NULL);
        }
        listaddbacknode(&newlist, newnode);
        head = head->next;
    }
    return (newlist);
}