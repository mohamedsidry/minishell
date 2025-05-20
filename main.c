#include "include/header.h"



int main(int argc, char *argv[], char *envp[])
{
	char *line;

	(void)argc;
	(void)argv;
	(void)envp;
	while (true)
	{
		proreadline(PROMPT, &line);
		if (!line)
			break ;
		ft_isexit(line);
		printf("line is '%s'\n", line);
		nullstr(&line);
	}
	free(line);
	return (EXIT_SUCCESS);
}
