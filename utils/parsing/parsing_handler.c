#include "../../include/header.h"


void parsing_handler(t_command **cmds, char **line, t_list **envlst)
{
	t_list *tokens;
	tokens = NULL;
	(void)cmds;
	(void)envlst;

	lexer(&tokens, *line); // TODO: tokenize and add context to tokens ! .
	//expander(&units, envlst);
	//tokenvaliditor(&units); //VALIDATE '""' '| spc |' '|' in start | at end 
	//cmds_generater(cmds, &units); //TODO: GENERATE commands !
	//release_tokens(&units); //TODO: free units we dont need them we have commands !
	
	// for test free leaks !
	display_tokens(tokens);
	listclearnodes(&tokens, listdeletenode);

}
