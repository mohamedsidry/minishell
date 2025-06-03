#include "../../include/header.h"


static void listcontent(t_list *list, char *context);

void read_command(t_command *cmd)
{
    if (!cmd)
    {
        printf("NULL COMMAND !!!!\n");
        return ;

    }
    printf("executable : %s\n", cmd->executable);
    if (cmd->args || 0 == printf("empty args\n"))
        listcontent(cmd->args, "command args");
    if (cmd->infiles || 0 == printf("empty infiles\n"))
        listcontent(cmd->infiles, "command infiles");
    if (cmd->outfiles || 0 == printf("empty oufile\n"))
        listcontent(cmd->outfiles, "command args");
    if (cmd->appendfiles || 0 == printf("empty appends\n"))
        listcontent(cmd->appendfiles, "command append files");
    if (cmd->limiters || 0 == printf("empty limiters\n"))
        listcontent(cmd->limiters, "command limiters");
}


static void listcontent(t_list *list, char *context)
{
    int idx;

    idx = 0;
    if (!list)
    {
        printf("context %s is empty !!\n", context);
        return ;
    }
    while (list)
    {
        printf("%s [%d] is content is %s\n", context, idx, (char *)list->content);
        list = list->next;
        idx++;
    }
}
