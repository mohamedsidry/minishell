#include "../../include/exec.h"

int	builtin_cd(t_list *args, t_list **env)
{
	char	*path;
	char	*old_pwd;
	char	*new_pwd;
	int		result;

	path = get_cd_path(args, *env);
	if (!path)
		return (1);
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (handle_cd_error("getcwd failed", NULL, NULL));
	if (chdir(path) != 0)
		return (handle_cd_error("cd", old_pwd, NULL));
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (handle_cd_error("getcwd failed", old_pwd, NULL));
	result = update_pwd_vars(env, old_pwd, new_pwd);
	free(old_pwd);
	free(new_pwd);
	return (result);
}

char	*get_cd_path(t_list *args, t_list *env)
{
	char	*path;

	if (args && args->content)
		return ((char *)args->content);
	path = getvalue(env, "HOME");
	if (!path)
	{
		printf("cd: HOME not set\n");
		return (NULL);
	}
	return (path);
}

int	handle_cd_error(char *msg, char *old_pwd, char *new_pwd)
{
	perror(msg);
	if (old_pwd)
		free(old_pwd);
	if (new_pwd)
		free(new_pwd);
	return (1);
}

int	update_pwd_vars(t_list **env, char *old_pwd, char *new_pwd)
{
	setvalue(*env, "OLDPWD", ft_strdup(old_pwd));
	setvalue(*env, "PWD", ft_strdup(new_pwd));
	return (0);
}

int	builtin_export(t_list *args, t_list **env)
{
	t_list	*current;
	char	*key;
	char	*value;
	char	*equal_sign;

	if (!args)
	{
		builtin_env(*env);
		return (0);
	}
	current = args;
	while (current)
	{
		equal_sign = ft_strchr(current->content, '=');
		if (equal_sign)
		{
			*equal_sign = '\0';
			key = (char *)current->content;
			value = equal_sign + 1;
			setvalue(*env, key, value);
			*equal_sign = '=';
		}
		current = current->next;
	}
	return (0);
}

int	builtin_unset(t_list *args, t_list **env)
{
	t_list	*current;
	t_list	*env_node;
	t_list	*prev;

	current = args;
	while (current)
	{
		env_node = *env;
		prev = NULL;
		while (env_node)
		{
			if (ft_strcmp(((t_envnode *)env_node->content)->key,
				(char *)current->content) == 0)
			{
				if (prev)
					prev->next = env_node->next;
				else
					*env = env_node->next;
				delete_node(&env_node);
				break ;
			}
			prev = env_node;
			env_node = env_node->next;
		}
		current = current->next;
	}
	return (0);
}

int	builtin_env(t_list *env)
{
	t_list		*current;
	t_envnode	*node;

	current = env;
	while (current)
	{
		node = (t_envnode *)current->content;
		if (node && node->key && node->value)
			printf("%s=%s\n", node->key, node->value);
		current = current->next;
	}
	return (0);
}
