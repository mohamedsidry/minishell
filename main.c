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
	while (true)
	{
		proreadline(PROMPT, &line, &lstenv);
		ft_isexit(line, &lstenv);
		add_history(line);
		parsing_handler(&cmds, &line, &lstenv);
		printf("KEY   = '%s'\n", line);
		printf("VALUE = '%s'\n", getvalue(lstenv, line));
		nullstr(&line);
	}
	free(line);
	return (EXIT_SUCCESS);
}
