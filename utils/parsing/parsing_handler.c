#include "../../include/header.h"


void parsing_handler(t_list **commands, char **line)
{
	t_list *tokens;
	tokens = NULL;

	lexer(&tokens, *line); // TODO: tokenize and add context to tokens ! .
	validator(&tokens); //TODO: validate '""' '| spc |' '|' in start | at end 
	serializer(commands, tokens); //TODO: GENERATE commands !	
	listclearnodes(&tokens, listdeletenode); //TODO: delete tokens since we created commands from them !
}
