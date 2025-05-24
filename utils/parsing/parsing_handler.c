#include "../../include/header.h"


void parsing_handler(t_command **cmds, char **line, t_list **envlst)
{
	t_list *units;
	units = NULL;
	(void)cmds;
	(void)envlst;

	lixer(&units, *line);
	//tokenizer(&units); //TODO: TOKENIZE the units .
	//expander(&units, envlst);
	//tokenvaliditor(&units); //VALIDATE '""' '| spc |' '|' in start | at end 
	//cmds_generater(cmds, &units); //TODO: GENERATE commands !
	//release_tokens(&units); //TODO: free units we dont need them we have commands !
	
	// for test free leaks !
	listclearnodes(&units, listdeletenode);
	display_tokens(units);
}
