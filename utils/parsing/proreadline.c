#include "../../include/header.h"




void proreadline(char *prompt, char **input, t_list **envlst)
{
	if (!input)
		return ;
	*input = readline(prompt);
	if  (*(input))
		return ;
	env_manager(envlst, NULL, DELETE); //DELETE ENV LIST VARS BEFORE EXIT !
	write(1, EXITCMD, ft_strlen(EXITCMD));
	write(1, "\n", 1);
	exit(EXIT_SUCCESS);
}
