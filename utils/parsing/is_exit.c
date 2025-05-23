# include "../../include/header.h"


void ft_isexit(char *input, t_list **envlst)
{
	char	*cmd;

	cmd = ft_trimspaces(input);
	if (!cmd)
	{
		free(input);
		write(2, ERRMEMO, ft_strlen(ERRMEMO));
		env_manager(envlst, NULL, DELETE); //DELETE ENV LIST VARS BEFORE EXIT !
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp(cmd, EXITCMD))
	{
		free(cmd);
		free(input);
		env_manager(envlst, NULL, DELETE); //DELETE ENV LIST VARS BEFORE EXIT !
		exit (EXIT_SUCCESS);
	}
	free(cmd);
}
