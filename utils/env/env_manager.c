
#include "../../include/header.h"

static void *create_env(t_list **lstenv, char *envp[]);
static void *delete_env(t_list **lstenv);
static void *read_env(t_list *lstenv);
void        *patch_env(t_list *lstenv);

void *env_manager(t_list **env, char **envp ,t_action crud)
{
    void *ptr;

    if (!env)
        return (NULL);
    if (crud & CREATE)
        ptr = create_env(env, envp);
    if (crud & DELETE)
        ptr = delete_env(env);
    if (crud & READ)
        ptr = read_env(*env);
    if (crud & PATCH)
        ptr = patch_env(*env); //NOTE: update path to include cwd and increase SHLVL
    return (ptr);
}



static void *create_env(t_list **lstenv, char *envp[])
{
    size_t idx;
    t_envnode *node;
    t_list *current;
    idx = 0;

    while (envp[idx])
    {
        node = create_node(envp[idx]);
        if (!node)
        {
            listclearnodes(lstenv, delete_node);
            return (NULL);
        }
        current = listcreatenode(node);
        if (!current)
        {
            listclearnodes(lstenv, delete_node);
            return (NULL);
        }
        listaddbacknode(lstenv, current);
        idx++;
    }
    return (lstenv);
}

static void *delete_env(t_list **lstenv)
{
    listclearnodes(lstenv, delete_node);
    return lstenv;
}



static void *read_env(t_list *lstenv)
{
    if (!lstenv)
    {
        write(1, "Empty env var list !\n", 22);
        return (NULL);
    }
    while (lstenv)
    {
        read_node(lstenv->content);
        lstenv = lstenv->next;
    }
    return (lstenv);
}

void  *patch_env(t_list *lstenv)
{
    char *pwd;
    char *path;
    char *shlvl;

    if (!lstenv)
        return (NULL);
    pwd = getvalue(lstenv, PWD);
    if (pwd)
    {
        path = getvalue(lstenv, PATH);
        if (!path)
            setvalue(lstenv, PATH, ft_strdup(pwd));
        else if (!ft_strstr(path, pwd))
            setvalue(lstenv, PATH, ft_joinstrs(":",2, path, pwd));
    }
    shlvl = getvalue(lstenv, SHLVL);
    if (shlvl)
        setvalue(lstenv, SHLVL, ft_itoa(shlvl));
    return (NULL);
}
