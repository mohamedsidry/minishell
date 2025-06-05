#include "../../include/header.h"




t_command *update_command(t_command *cmd, t_list *node, t_token type)
{
    t_list *new;


    new = listnodedup(node);
    if (!new)
        return (NULL);

    if (type == COMMAND)
        listaddbacknode(&cmd->args, new);
    else if (type == FILE_IN)
        listaddbacknode(&cmd->infiles, new);
    else if (type == FILE_OUT)
        listaddbacknode(&cmd->outfiles, new);
    else if (type == FILE_APPEND)
        listaddbacknode(&cmd->appendfiles, new);
    else if (type == LIMITER)
        listaddbacknode(&cmd->limiters, new);
    else
    {
        listdeletenode(&new);
        return (cmd);
    }
    if (type == FILE_IN || type == FILE_OUT || type == FILE_APPEND)
        listaddbacknode(&cmd->redirections, listnodedup(node));
    return (cmd);
}

/*
	FILE_IN,
	FILE_OUT,
	REDIRECT_IN,
	REDIRECT_OUT,
	FILE_APPEND,
*/

/*
    char *executable;
	size_t pid;
	t_list *args;
	int runinbackground;
	int waitforit;
	t_list *infiles;
	t_list *outfiles;
	t_list *appendfiles;
	t_list *limiters;
	int pipe[2];
*/