#include "../../include/header.h"




void proreadline(char *prompt, char **input)
{
	if (!input)
		return ;
	*input = readline(prompt);
	if  (*(input))
		return ;
	write(1, EXITCMD, ft_strlen(EXITCMD));
	write(1, "\n", 1);
	exit(EXIT_SUCCESS);
}
