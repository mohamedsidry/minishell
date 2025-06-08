
#include "../../include/header.h"

static int validate_pipe(t_list *token);
static int validate_redirection(t_list *token);
static int isredirection(t_token type);
static int ispipe(t_token type);

int validsyntax(t_list *token)
{
    if (!token)
        return (NONVALID);
    if (ispipe(token->type))
        return validate_pipe(token);
    else if (isredirection(token->type))
        return validate_redirection(token);
    else
        return (VALID);
}


static int validate_pipe(t_list *token)
{
    if (!token->prev)
    {
        printf("syntax error near unexpected token `|'\n");
        return (NONVALID);
    }
    else if (!token->next)
    {
        printf("syntax error: unexpected end of file\n");
        return (NONVALID);
    }
    else if (ispipe(token->next->type))
    {
        printf("syntax error near unexpected token `|'\n");
        return (NONVALID);
    }
    else
        return (VALID);
}


static int validate_redirection(t_list *token)
{
    if (!token)
        return (NONVALID);
    else if (!token->next)
    {
        printf("syntax error near unexpected token `newline'\n");
        return (NONVALID);
    }
    else if (isredirection(token->next->type) || ispipe(token->next->type))
    {
        printf("syntax error near unexpected token `%s'\n", (char *)token->next->content);
        return (NONVALID);
    }
    else
        return (VALID);
}


static int isredirection(t_token type)
{
    return (type == REDIRECT_IN || type == REDIRECT_OUT || type == APPEND || type == HEREDOC);
}

static int ispipe(t_token type)
{
    return (type == PIPE);
}