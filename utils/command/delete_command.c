#include "../../include/header.h"


void delete_command(t_command **cmd)
{
    if (!cmd || !*cmd)
        return ;
    nullstr(&(*cmd)->executable);
    listclearnodes(&(*cmd)->args, listdeletenode);
    listclearnodes(&(*cmd)->infiles, listdeletenode);
    listclearnodes(&(*cmd)->outfiles, listdeletenode);
    listclearnodes(&(*cmd)->appendfiles, listdeletenode);
    listclearnodes(&(*cmd)->limiters, listdeletenode);
    listclearnodes(&(*cmd)->redirections, listdeletenode);
    (*cmd)->pipe[0] = -1;
    (*cmd)->pipe[1] = -1;
    free(*cmd);
    *cmd = NULL;
    //TODO: delete anything allocated here in command 
    // basicly just run listclearnode on lists hahahaha .
}
/*
	char *executable;
	size_t pid;
	t_list *args;
	t_list *infiles;
	t_list *outfiles;
	t_list *appendfiles;
	t_list *limiters;
	int pipe[2];
*/
