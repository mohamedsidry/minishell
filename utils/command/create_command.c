#include "../../include/header.h"

t_command *create_command(void)
{
    t_command *cmd;

    cmd = ft_calloc(sizeof(t_command), 1);
    if (!cmd)
        return (NULL);
    cmd->pid = -1;
    cmd->executable = NULL;
    cmd->args = NULL;
    cmd->infiles = NULL;
    cmd->outfiles = NULL;
    cmd->appendfiles = NULL;
    cmd->limiters = NULL;
    cmd->pipe[0] = -1;
    cmd->pipe[1] = -1;

    //TODO: set all to null memset(cmd, sizeof(t_command));
    //TODO: set pipe read and write end to -1 .
    return (cmd);
}


/*
	char *executable;
	size_t pid;
	t_list *args;
	int runinbackground;
	int waitforit;
	t_list *infiles;
	t_list *outfiles;
	t_list *appendfiles;
*/