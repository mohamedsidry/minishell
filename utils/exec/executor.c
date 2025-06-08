#include "../../include/exec.h"

int g_signal_received = 0;

int	execute_pipeline(t_list *commands, t_list **env)
{
	int		exit_status;
	t_list	*current;

	if (!commands)
		return (1);
	// if only ONE command, handle it simply
	if (listsize(commands) == 1)
		return (execute_single_command(commands->content, env));
	setup_signals(); // handle ctrl+C
	if (setup_pipes(commands) != 0) // create pipes between commands
		return (1);
	// execute each command in the pipeline
	current = commands;
	while (current)
	{
		if (fork_and_execute(current->content, *env) != 0)
			break ;
		current = current->next;
	}
	cleanup_pipes(commands);  // close all pipes
	exit_status = wait_for_children(commands);  // wait for all to finish
	return (exit_status);
}

int	fork_and_execute(t_command *cmd, t_list *env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0) // child process (the copy)
	{
		handle_child_process(cmd, env); // child does the actual work
		exit(1);  // child should never reach here
	}
	else if (pid > 0)
	{
		cmd->pid = pid; // remember the child's ID
		handle_parent_process(cmd); // parent manages pipes
		return (0);
	}
	return (1);
}

int	execute_single_command(t_command *cmd, t_list **env)
{
	char	*executable;

	if (!cmd || !cmd->args || !cmd->args->content)
		return (1);
	executable = (char *)cmd->args->content;
	if (is_builtin(executable))
		return (execute_builtin(cmd, env));
	if (setup_redirections(cmd) != 0)
		return (1);
	return (execute_external(cmd, *env));
}

int	setup_pipes(t_list *commands)
{
	t_list		*current;
	t_command	*cmd;

	current = commands;
	// go through each command (except the last one)
	while (current && current->next)
	{
		cmd = (t_command *)current->content;
		cmd->pipe[0] = -1;
		cmd->pipe[1] = -1;
		// create a pipe for THIS command
		if (pipe(cmd->pipe) == -1)
		{
			perror("pipe");
			return (1);
		}
		// cmd->pipe[0] = read end
        // cmd->pipe[1] = write end
		current = current->next;
	}
	return (0);
}

void	cleanup_pipes(t_list *commands)
{
	t_list		*current;
	t_command	*cmd;

	current = commands;
	while (current)
	{
		cmd = (t_command *)current->content;
		if (cmd->pipe[0] != -1) // succesful close (0)
		{
			close(cmd->pipe[0]);
			cmd->pipe[0] = -1; // reset 
		}
		if (cmd->pipe[1] != -1) // same here
		{
			close(cmd->pipe[1]);
			cmd->pipe[1] = -1;
		}
		current = current->next;
		 
	}
}

int	wait_for_children(t_list *commands)
{
	t_list		*current;
	t_command	*cmd;
	int			status;
	int			exit_status;

	current = commands;
	exit_status = 0;
	while (current)
	{
		cmd = (t_command *)current->content;
		if (cmd->pid > 0)
		{
			waitpid(cmd->pid, &status, 0); 
			exit_status = get_exit_status(status);
		}
		current = current->next;
	}
	return (exit_status);
}
