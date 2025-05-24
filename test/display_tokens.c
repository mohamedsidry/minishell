#include "../include/header.h"



void display_tokens(t_list *lst)
{
    if (!lst)
    {
        printf("EMPTY TOKEN LIST !\n");
        return ;
    }
    while (lst)
    {
        printf("TOKEN CONTENT : %s\n", (char *)lst->content);
        lst = lst->next;
    }
}