#ifndef EXEC_H
# define EXEC_H

# include "typedef.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h> 
#define RL_LIBRARY
# include <readline/readline.h>
# include <readline/history.h>
# include "header.h"

/* Global variable for signal handling (as required by subject) */
extern int g_signal_received;

/* Core execution functions */
int		execute_pipeline(t_list *commands, t_list **env);
int		execute_single_command(t_command *cmd, t_list **env);
int		setup_redirections(t_command *cmd);
int		setup_pipes(t_list *commands);
void	cleanup_pipes(t_list *commands);

/* Built-in commands */
int		is_builtin(char *cmd);
int		execute_builtin(t_command *cmd, t_list **env);
int		builtin_echo(t_list *args);
int		builtin_cd(t_list *args, t_list **env);
int		builtin_pwd(void);

/* More built-ins */
int		builtin_export(t_list *args, t_list **env);
int		builtin_unset(t_list *args, t_list **env);
int		builtin_env(t_list *env);
int		builtin_exit(t_list *args);

/* External command execution */
char	*find_executable(char *cmd, t_list *env);
int		execute_external(t_command *cmd, t_list *env);
char	**build_argv(t_command *cmd);
void	free_argv(char **argv);

/* Signal handling */
void	setup_signals(void);
void	signal_handler(int sig);
void	signal_child(void);
void	signal_parent(void);

/* Process management */
int		wait_for_children(t_list *commands);
void	handle_child_process(t_command *cmd, t_list *env);
void	handle_parent_process(t_command *cmd);
int		get_exit_status(int status);
void	setup_pipe_child(t_command *cmd);
void	setup_pipe_parent(t_command *cmd);

int	setup_input_redirections(t_command *cmd);
int	setup_output_redirections(t_command *cmd);
int	setup_redirections(t_command *cmd);
int	setup_append_redirections(t_command *cmd);
int	setup_heredoc(t_command *cmd);

char	*search_in_path(char *path_copy, char *cmd);
void	exec_child(char *executable, char **argv, char **envp);
int		handle_parent(pid_t pid, char *exec, char **argv, char **envp, int *status);
char	**cleanup_argv(char **argv, int up_to);
int		fork_and_execute(t_command *cmd, t_list *env);

char	*get_cd_path(t_list *args, t_list *env);
int		handle_cd_error(char *msg, char *old_pwd, char *new_pwd);
int		update_pwd_vars(t_list **env, char *old_pwd, char *new_pwd);

#endif /* EXEC_H */