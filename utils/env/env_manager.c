
#include "../../include/header.h"

static void *create_env(t_list **lstenv, char *envp[]);
static void *delete_env(t_list **lstenv, char *envp[]);
static void *read_env(t_list *lstenv, char *envp[]);

void *env_manager(t_list **env, char **envp ,t_action crud)
{
    void *ptr;

    if (!env)
        return (NULL);
    if (crud & CREATE)
        ptr = create_env(env, envp);
    if (crud & DELETE)
        ptr = delete_env(env, envp);
//    if (crud & UPDATE) //TODO :
//        ptr = update_env(env, envp);
    if (crud & READ)
        ptr = read_env(*env, envp);
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
        current->content = node;
        listaddbacknode(lstenv, current);
        idx++;
    }
    return (lstenv);
}

static void *delete_env(t_list **lstenv, char *envp[])
{
    (void)envp;
    listclearnodes(lstenv, delete_node);
    return lstenv;
}



static void *read_env(t_list *lstenv, char *envp[])
{
    (void)envp;
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