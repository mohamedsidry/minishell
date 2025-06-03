#include "../../include/header.h"


t_command *command_manager(t_command **cmds, t_list *node, t_token tkn, t_action crud)
{
    t_command *ptr;

    if (!cmds)
        return (NULL);
    ptr = *cmds;
    if (crud == CREATE)
        ptr = create_command();
    if (crud == DELETE)
        delete_command(cmds);
    if (crud == UPDATE)
        ptr = update_command(*cmds, node, tkn);
    if (crud == READ)
        read_command(*cmds);
    return (ptr);
}