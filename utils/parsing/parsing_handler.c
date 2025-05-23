#include "../../include/header.h"


void parsing_handler(t_command **cmds, char **line, t_list **envlst)
{
	t_list *units;
	units = NULL;
	(void)cmds;
	(void)line;
	(void)envlst;

	lixer(&units, *line);
}


void lixer(t_list **units, char *line)
{
	size_t idx;
	size_t success;

	idx = 0;
	while (line[idx])
	{
		if (ft_isspace(line[idx]))
			success = match_space(&line[idx], &idx);
		else if (ft_isredirection(line[idx]))
			success = redirection_handler(units, &line[idx], &idx);
		else if (ft_ispipe(line[idx]))
			success = pipe_handler(units, &line[idx], &idx);
		else if (ft_isquote(line[idx]))
			success = quotes_handler(units, &line[idx], &idx);
		if (!success)
			//TODO: FAILURE SOMEWARE !
	}
}

size_t redirection_handler(t_list **units, char *line, size_t *pos)
{
	t_list *node;
	size_t idx;
	char *content;

	idx = 1;
	if (line[0] == line[1])
		idx++;
	content = ft_calloc(idx + 1, sizeof(char));
	if (!content)
		return (0);
	ft_strlcpy(content, line, idx + 1);
	node = listcreatenode(content);
	if (!node)
	{
		nullstr(&content);
		return(0);
	}
	listaddbacknode(node);
	idx += *pos;
	*pos = idx;
	return (idx);
}


size_t pipe_handler(t_list **units, char *line, size_t *pos)
{
	t_list *node;
	size_t idx;
	char *content;

	idx = 1;
	if (line[0] == line[1])
		idx++;
	content = ft_calloc(idx + 1, sizeof(char));
	if (!content)
		return (0);
	ft_strlcpy(content, line, idx + 1);
	node = listcreatenode(content);
	if (!node)
	{
		nullstr(&content);
		return(0);
	}
	listaddbacknode(node);
	idx += *pos;
	*pos = idx;
	return (idx);
}


size_t quotes_handler(t_list **units, char *line, size_t *pos)
{
	t_list *node;
	size_t idx;
	char *content;

}