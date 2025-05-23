#include "../include/header.h"

void display_env(t_list *envlst)
{
    if (DEBUGMODE)
    {
        if (!envlst)
        {
            printf("Empty ENV VARIABLES !\n");
            return ;
        }
        while (envlst)
        {
            read_node(envlst->content);
            envlst = envlst->next;
        }
    }
}