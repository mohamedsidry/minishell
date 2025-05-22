#include "include/header.h"



int main(int argc, char *argv[], char *envp[])
{
	char *line;
	t_command *cmds;
	t_list *lstenv;

	lstenv = NULL;
	cmds = NULL;
	(void)argc;
	(void)argv;
	modenotifier();
	run_unit_tests();
	env_manager(&lstenv, envp, CREATE);
	env_manager(&lstenv, envp, READ);
	env_manager(&lstenv, envp, DELETE);
	while (true)
	{
		proreadline(PROMPT, &line);
		ft_isexit(line);
		add_history(line);
		parsing_handler(&cmds, &line, &envp);
		printf("line is '%s'\n", line);
		nullstr(&line);
	}
	free(line);
	return (EXIT_SUCCESS);
}
