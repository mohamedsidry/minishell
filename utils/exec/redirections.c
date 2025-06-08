#include "../../include/exec.h"

int	setup_redirections(t_command *cmd)
{
	if (setup_input_redirections(cmd) != 0)
		return (1);
	if (setup_output_redirections(cmd) != 0)
		return (1);
	if (setup_heredoc(cmd) != 0)
		return (1);
	return (0);
}

int	setup_input_redirections(t_command *cmd)
{
	t_list	*current;
	int		fd;

	current = cmd->infiles;
	while (current)
	{
		fd = open((char *)current->content, O_RDONLY);
		if (fd == -1)
		{
			perror((char *)current->content);
			return (1);
		}
		if (dup2(fd, 1) == -1)
		{
			perror("dup2");
			close(fd);
			return (1);
		}
		close(fd);
		current = current->next;
	}
	return (0);
}

int	setup_output_redirections(t_command *cmd)
{
	t_list	*current;
	int		fd;

	current = cmd->outfiles;
	while (current)
	{
		fd = open((char *)current->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror((char *)current->content);
			return (1);
		}
		if (dup2(fd, 1) == -1)
		{
			perror("dup2");
			close(fd);
			return (1);
		}
		close(fd);
		current = current->next;
	}
	return (setup_append_redirections(cmd));
}

int	setup_append_redirections(t_command *cmd)
{
	t_list	*current;
	int		fd;

	current = cmd->appendfiles;
	while (current)
	{
		fd = open((char *)current->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			perror((char *)current->content);
			return (1);
		}
		if (dup2(fd, 1) == -1)
		{
			perror("dup2");
			close(fd);
			return (1);
		}
		close(fd);
		current = current->next;
	}
	return (0);
}

int	setup_heredoc(t_command *cmd)
{
	t_list	*current;
	int		pipe_fd[2];
	char	*line;
	char	*limiter;

	current = cmd->limiters;
	while (current)
	{
		limiter = (char *)current->content;
		if (pipe(pipe_fd) == -1)
			return (1);
		while ((line = readline("> ")) != NULL)
		{
			if (ft_strcmp(line, limiter) == 0)
			{
				free(line);
				break ;
			}
			write(pipe_fd[1], line, ft_strlen(line));
			write(pipe_fd[1], "\n", 1);
			free(line);
		}
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 1);
		close(pipe_fd[0]);
		current = current->next;
	}
	return (0);
}