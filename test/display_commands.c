
#include "../include/header.h"

void display_commands(t_list *command)
{
    if (DEBUGMODE)
    {
        if (!command)
        {
            printf("Empty command struct !\n");
            return ;
        }
        while (command)
        {
            command_manager((t_command **)&(command)->content, NULL, 0, READ);
            command = command->next;
        }
    }
}