#include "../../include/exec.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	execute_builtin(t_command *cmd, t_list **env)
{
	char	*executable;

	if (!cmd || !cmd->args || !cmd->args->content)
		return (1);
	executable = (char *)cmd->args->content;
	if (ft_strcmp(executable, "echo") == 0)
		return (builtin_echo(cmd->args->next));
	if (ft_strcmp(executable, "cd") == 0)
		return (builtin_cd(cmd->args->next, env));
	if (ft_strcmp(executable, "pwd") == 0)
		return (builtin_pwd());
	if (ft_strcmp(executable, "export") == 0)
		return (builtin_export(cmd->args->next, env)); // added for export 
	if (ft_strcmp(executable, "unset") == 0)
		return (builtin_unset(cmd->args->next, env));
	if (ft_strcmp(executable, "env") == 0)
		return (builtin_env(*env));
	if (ft_strcmp(executable, "exit") == 0)
		return (builtin_exit(cmd->args->next));
	return (1);
}

int	builtin_echo(t_list *args)
{
	t_list	*current;
	int		newline;

	newline = 1;
	current = args;
	if (current && current->content && 
		ft_strcmp((char *)current->content, "-n") == 0)
	{
		newline = 0;
		current = current->next;
	}
	while (current)
	{
		printf("%s", (char *)current->content);
		if (current->next)
			printf(" ");
		current = current->next;
	}
	if (newline)
		printf("\n");
	return (0);
}

int	builtin_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}

int	builtin_exit(t_list *args)
{
	int	exit_code;

	exit_code = 0;
	if (args && args->content)
	{
		exit_code = atoi((char *)args->content);
		if (exit_code < 0 || exit_code > 255)
			exit_code = 1;
	}
	printf("exit\n");
	exit(exit_code);
}
