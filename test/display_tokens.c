#include "../include/header.h"


static void map_type(t_token token);
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
        map_type(lst->type);
        lst = lst->next;
    }
}

static void map_type(t_token token)
{
    switch(token)
    {
        case PIPE:
            printf("TYPE : %s\n", "PIPE");
            break;
        case COMMAND:
            printf("TYPE : %s\n", "COMMAND");
            break;
	    case FILE_IN:
            printf("TYPE : %s\n", "FILE_IN");
            break;
	    case FILE_OUT:
            printf("TYPE : %s\n", "FILE_OUT");
            break;
	    case FILE_APPEND:
            printf("TYPE : %s\n", "FILE_APPEND");
            break;
	    case APPEND:
            printf("TYPE : %s\n", "APPEND");
            break;
	    case HEREDOC:
            printf("TYPE : %s\n", "HEREDOC");
            break;
	    case LIMITER:
            printf("TYPE : %s\n", "LIMITER");
            break;
	    case AND:
            printf("TYPE : %s\n", "AND");
            break;
	    case OR:
            printf("TYPE : %s\n", "OR");
            break;
	    case RUNBACKGROUND:
            printf("TYPE : %s\n", "RUNBACKGROUND");
            break;
	    case PIPEAND:
            printf("TYPE : %s\n", "PIPEAND");
            break;
	    case SEQUENCE:
            printf("TYPE : %s\n", "SEQUENCE");
            break;
        case REDIRECT_IN:
            printf("TYPE : %s\n", "REDIRECTION IN");
            break;
	    case REDIRECT_OUT:
            printf("TYPE : %s\n", "REDIRECTION OUT");
            break;
        case ARG:
            printf("TYPE : %s\n", "COMMAND ARG");
            break;
            
        default:
            printf("TYPE : UNKNOWN !\n");
    }
}