#include "../../include/header.h"

static char *extractkey(char *envp);
static char *extractvalue(char *envp);

t_envnode *create_node(char *envp)
{
    t_envnode *node;

    if (!envp)
        return (NULL);
    node = ft_calloc(sizeof(t_envnode), 1);
    if (!node)
        return (NULL);
    node->key = extractkey(envp);
    node->value = extractvalue(envp);
    if (!node->key || !node->value)
    {
        free(node->key);
        free(node->value);
        free (node);
        return (NULL);
    }
    return (node);
}





static char *extractkey(char *envp)
{
    char *sep;
    char *key;


    sep = ft_strchr(envp, '=');
    if (!sep)
        return (NULL);
    key = ft_calloc((sep - envp + 1), 1);
    if (!key)
        return (NULL);
    ft_strlcpy(key, envp, sep - envp + 1);
    return (key);
}


static char *extractvalue(char *envp)
{
    char *sep;
    char *value;


    sep = ft_strchr(envp, '=');
    if (!sep)
        return (NULL);
    sep++;
    value = ft_strdup(sep);
    return (value);
}