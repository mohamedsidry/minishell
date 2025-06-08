#include "../../include/exec.h"

void	handle_child_process(t_command *cmd, t_list *env)
{
	char	*executable;
	char	**argv;
	char	**envp;

	signal_child();
	setup_pipe_child(cmd); // connect pipes to stdin/stdout
	if (setup_redirections(cmd) != 0) // handle < > >> <<
		exit(1);
	// is this a builtin command?
	if (is_builtin((char *)cmd->args->content))
		exit(execute_builtin(cmd, &env));
	// external command need to find and execute it
	executable = find_executable((char *)cmd->args->content, env);
	if (!executable)
	{
		printf("%s: command not found\n", (char *)cmd->args->content); // clear exit
		exit(127);
	}
	argv = build_argv(cmd);  // convert arguments to array
	envp = env_serializer(env); // convert environment to array
	execve(executable, argv, envp);
	perror("execve");
	exit(127);
}

void	handle_parent_process(t_command *cmd)
{
	setup_pipe_parent(cmd); // yes im dumb
}

void	setup_pipe_child(t_command *cmd)
{
	if (cmd->pipe[1] != -1)
	{
		dup2(cmd->pipe[1], 1);
		close(cmd->pipe[1]);
	}
	if (cmd->pipe[0] != -1)
		close(cmd->pipe[0]);
}

void	setup_pipe_parent(t_command *cmd)
{
	if (cmd->pipe[1] != -1) // close write end (parent doesnt write to this pipe)
		close(cmd->pipe[1]);

	// if there is a read end make it our new stdin
	if (cmd->pipe[0] != -1)
	{
		dup2(cmd->pipe[0], 1); // next command reads from this pipe
		close(cmd->pipe[0]);
	}
}

int	get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}
