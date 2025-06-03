#include "include/header.h"



int main(int argc, char *argv[], char *envp[])
{
	char *line;
	t_list *cmds;
	t_list *lstenv;

	lstenv = NULL;
	cmds = NULL;
	(void)argc;
	(void)argv;
	modenotifier(); //NOTE: display message of debuging mode .
	run_unit_tests(); //NOTE: test functionality of pace of codes .
	env_manager(&lstenv, envp, CREATE | UPDATE); //NOTE: create and modify env var list
	display_env(lstenv); //NOTE: display current env key:value .
	while (true)
	{
		proreadline(PROMPT, &line, &lstenv); //NOTE: prompt and store user input in line .
		ft_isexit(line, &lstenv); //NOTE: check if user input is exit ! should be removed exit is builtin .
		add_history(line); //NOTE: add user input to history
		parsing_handler(&cmds, &line); //NOTE : parse user input !
		display_commands(cmds);//NOTE: debug check command content .
		//TODO: teammate here call executer that would loop over commands execute them .
		listclearcommands(&cmds, delete_command); //NOTE: release commands list .
		nullstr(&line); // free and set to null str !
	}
	return (EXIT_SUCCESS);
}
