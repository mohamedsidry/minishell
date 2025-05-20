# include "../../include/header.h"


void ft_isexit(char *input)
{
	char	*cmd;

	cmd = ft_trimspaces(input);
	if (!cmd)
	{
		free(input);
		write(2, ERRMEMO, ft_strlen(ERRMEMO));
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp(cmd, EXITCMD))
	{
		free(cmd);
		free(input);
		exit (EXIT_SUCCESS);
	}
	free(cmd);
}
