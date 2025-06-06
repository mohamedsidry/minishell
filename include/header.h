#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
#include <stdbool.h>

# include "const.h"
# include "utils.h"
# include "error.h"
# include "test.h" //TODO: removed in prodection !
# include "typedef.h"

void *env_manager(t_list **env, char **envp, t_action crud);
void ft_isexit(char *input, t_list **envlst);
void proreadline(char *prompt, char **strptr, t_list **envlst);
void parsing_handler(t_command **cmds, char **line, t_list **envlst);

#endif // HEADER_H
