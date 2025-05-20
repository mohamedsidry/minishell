#include "../../include/header.h"




void proreadline(char *prompt, char **input)
{
	if (!input)
		return ;
	*input = readline(prompt);
}
