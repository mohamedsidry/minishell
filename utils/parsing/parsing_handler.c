#include "../../include/header.h"


void parsing_handler(t_command **cmds, char **line, t_list **envlst)
{
	t_list *tokens;
	t_list *commands;
	commands = NULL;
	tokens = NULL;
	(void)cmds;
	(void)envlst;

	lexer(&tokens, *line); // TODO: tokenize and add context to tokens ! .
	validator(&tokens); //TODO: validate '""' '| spc |' '|' in start | at end 
	serializer(&commands, tokens); //TODO: GENERATE commands !	
	display_commands(commands);
	listclearcommands(&commands, delete_command);
	//command_manager(&commands, NULL, 0, READ);
	//display_tokens(tokens);
	listclearnodes(&tokens, listdeletenode);
}
