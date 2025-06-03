#include "../../include/header.h"


static void listcontent(t_list *list, char *context);

void read_command(t_command *cmd)
{
    if (!cmd)
    {
        printf("NULL COMMAND !!!!\n");
        return ;

    }
    if (cmd->args || 0 == printf("args is empty\n"))
        listcontent(cmd->args, "args : ");
    if (cmd->infiles || 0 == printf("infile is empty\n"))
        listcontent(cmd->infiles, "infiles : ");
    if (cmd->outfiles || 0 == printf("outfile is empty\n"))
        listcontent(cmd->outfiles, "outfiles : ");
    if (cmd->appendfiles || 0 == printf("appen files empty\n"))
        listcontent(cmd->appendfiles, "append files : ");
    if (cmd->limiters || 0 == printf("limiters is empty\n"))
        listcontent(cmd->limiters, "limiters : ");
}


static void listcontent(t_list *list, char *context)
{
    int idx;

    idx = 0;
    if (!list)
    {
        printf("%s is empty !!\n", context);
        return ;
    }
    printf("%s", context);
    while (list)
    {
        printf("index[%d]=`%s`", idx, (char *)list->content);
        if (list->next)
            printf(", ");
        else
            printf("\n");
        list = list->next;
        idx++;
    }
    
}
