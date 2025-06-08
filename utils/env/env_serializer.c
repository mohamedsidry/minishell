
#include "../../include/header.h"

char **env_serializer(t_list *envlst)
{
    size_t size;
    size_t idx;
    char **arr;
    t_envnode *envp;

    if (!envlst)
        return (NULL);
    idx = 0;
    size = listsize(envlst);
    arr = ft_calloc(size + 1, sizeof(char *));
    if (!arr)
        return (NULL);
    while (idx < size)
    {
        envp = (t_envnode *)envlst->content;
        arr[idx] = ft_concatenate(envp->key, envp->value, "=");
        if (!arr[idx])
        {
            while ((int)idx > -1)
                free(arr[--idx]);
            free(arr);
            return (NULL);
        }
        idx++;
        envlst = envlst->next;
    }
    return (arr);
}