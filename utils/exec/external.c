#include "../../include/exec.h"

char	*find_executable(char *cmd, t_list *env)
{
	char	*path_env;
	char	*path_copy;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_env = getvalue(env, "PATH");
	if (!path_env)
		return (NULL);
	path_copy = ft_strdup(path_env);
	if (!path_copy)
		return (NULL);
	return (search_in_path(path_copy, cmd));
}

char	*search_in_path(char *path_copy, char *cmd)
{
	char	*path_token;
	char	*full_path;

	path_token = ft_strtok(path_copy, ":");
	while (path_token)
	{
		full_path = ft_concatenate(path_token, cmd, "/");
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		path_token = ft_strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

int	execute_external(t_command *cmd, t_list *env)
{
	char	*executable;
	char	**argv;
	char	**envp;
	pid_t	pid;
	int		status;

	if (!cmd || !cmd->args || !cmd->args->content)
		return (127);
	executable = find_executable((char *)cmd->args->content, env);
	if (!executable)
	{
		printf("%s: command not found\n", (char *)cmd->args->content);
		return (127);
	}
	argv = build_argv(cmd);
	envp = env_serializer(env);
	pid = fork();
	if (pid == 0)
		exec_child(executable, argv, envp);
	return (handle_parent(pid, executable, argv, envp, &status));
}

void	exec_child(char *executable, char **argv, char **envp)
{
	execve(executable, argv, envp);
	perror("execve");
	exit(127);
}

int	handle_parent(pid_t pid, char *exec, char **argv, char **envp, int *status) // to check later !! 
{
	if (pid > 0)
		waitpid(pid, status, 0);
	free(exec);
	free_argv(argv);
	free_argv(envp);
	if (pid > 0)
		return (get_exit_status(*status));
	return (1);
}

char	**build_argv(t_command *cmd)
{
	char	**argv;
	t_list	*current;
	int		count;
	int		i;

	if (!cmd || !cmd->args)
		return (NULL);
	count = listsize(cmd->args);
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	current = cmd->args;
	i = 0;
	while (current && i < count)
	{
		argv[i] = ft_strdup((char *)current->content);
		if (!argv[i])
			return (cleanup_argv(argv, i));
		current = current->next;
		i++;
	}
	argv[count] = NULL;
	return (argv);
}

char	**cleanup_argv(char **argv, int up_to)
{
	int	i;

	i = 0;
	while (i < up_to)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (NULL);
}

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
