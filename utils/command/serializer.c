#include "../../include/header.h"


t_list *serializer(t_list **commands, t_list *token)
{
    t_command *cmd;
    t_list *current;

    if (!commands || !token)
        return (NULL);
    while (token)
    {
        cmd = command_manager(&cmd, NULL, 0, CREATE);
        if (!cmd)
        {
            listclearcommands(commands, delete_command);
            return (NULL);
        }
        while (token && token->type != PIPE)
        {
            cmd = command_manager(&cmd, token, token->type, UPDATE);
            if (!cmd)
            {
                listclearcommands(commands, delete_command);
                return (NULL);
            }
            token = token->next;
        }
        current = listcreatenode(cmd);
        if (!current)
        {
            command_manager(&cmd, NULL, 0, DELETE);
            listclearcommands(commands, delete_command);
            return (NULL);
        }
        listaddbacknode(commands, current);
        if (token)
            token = token->next;
    }
    return (*commands);
}


