#include "../../include/header.h"


static int expand_check(char *str, t_list *env);
static int isexpandable(char *str);
static int isinsinglequote(char *str);
static int isindoublequote(char *str);
static char *extract_key(char *str);
static int ambiguous_check(char *value);
static int isredirection(t_token type);

int validexpanding(t_list *tokens, t_list *env)
{
    t_list *clone;
    t_list *tmp;

    clone = listmap(tokens, listnodedup);
    if (!clone)
    {
        printf("Error cloneing tokens !\n");
        return (NONVALID);
    }
    tmp = clone;
    while (tmp)
    {
        if (tmp->prev && isredirection(tmp->prev->type) && tmp->prev->type != HEREDOC)
        {
            if (expand_check(tmp->content, env) == NONVALID)
            {
                listclearnodes(&clone, listdeletenode);
                return (NONVALID);
            }
        }
        tmp = tmp->next;
    }
    listclearnodes(&clone, listdeletenode);
    return (VALID);
}


static int expand_check(char *str, t_list *env)
{
    char *key;
    char *value;
    char *dollar;

    if (!env)
        return (VALID);
    if (!isexpandable(str))
        return (VALID);
    dollar = ft_strchr(str, CHAR_DOLLAR);
    while (dollar)
    {
        if (!isinsinglequote(dollar) && !isindoublequote(dollar))
        {
            key = extract_key(dollar + 1);
            value = getvalue(env, key);
            if (value)
            {
                if (ambiguous_check(value))
                {
                    printf("$%s : ambiguous redirect\n", key);
                    nullstr(&key);
                    return (NONVALID);
                }
            }
            nullstr(&key);
        }
        dollar = ft_strchr(dollar + 1, CHAR_DOLLAR);
    }
    return (VALID);
}


static int isexpandable(char *str)
{
    if (!str || !*str)
        return (false);
    if (!ft_strchr(str, CHAR_DOLLAR))
        return (false);
    return (true);
}


static int isinsinglequote(char *str)
{
    int sqcount;

    sqcount = 0;

    while (*str)
    {
        if (*str == CHAR_SQUOTE)
            sqcount++;
        str++;
    }
    return (sqcount % 2);
}

static int isindoublequote(char *str)
{
    int sqcount;

    sqcount = 0;

    while (*str)
    {
        if (*str == CHAR_DQUOTE)
            sqcount++;
        str++;
    }
    return (sqcount % 2);
}


static char *extract_key(char *str)
{
    char *key;
    size_t size;
    
    size = 0;
    if (!str || !*str)
        return (NULL);
    while (str[size] && !ft_isspace(str[size]) && str[size] != CHAR_DOLLAR)
        size++;
    key = ft_calloc(size  + 1, sizeof(char));
    if (!key)
        return (NULL);
    ft_strlcpy(key, str, size + 1);
    return (key);
}

static int ambiguous_check(char *value)
{
    while (*value)
    {
        if (ft_isspace(*value))
        {
            while (*value && ft_isspace(*value))
                value++;
            break;
        }
        value++;
    }
    return (*value);
}

static int isredirection(t_token type)
{
    return (type == REDIRECT_IN || type == REDIRECT_OUT || type == APPEND || type == HEREDOC);
}