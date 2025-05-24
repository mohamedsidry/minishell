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
	modenotifier(); // display message of debuging mode .
	run_unit_tests(); // test functionality of pace of codes .
	env_manager(&lstenv, envp, CREATE | UPDATE); // create and modify env var list
	display_env(lstenv); //NOTE: display current env key:value .
	while (true)
	{
		proreadline(PROMPT, &line, &lstenv); // prompt and store user input in line .
		ft_isexit(line, &lstenv); // check if user input is exit !
		add_history(line); // add user input to history
		parsing_handler(&cmds, &line, &lstenv); // parse user input
		nullstr(&line); // free and set to null str !
	}
	return (EXIT_SUCCESS);
}
