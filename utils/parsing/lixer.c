#include "../../include/header.h"

static size_t redirection_handler(t_list **units, char *line, size_t *pos);
static size_t pipe_handler(t_list **units, char *line, size_t *pos);
static size_t quotes_handler(t_list **units, char *line, size_t *pos);
static size_t word_handler(t_list **units, char *line, size_t *pos);

void lixer(t_list **units, char *line)
{
	size_t idx;
	size_t success;

	idx = 0;
	while (line[idx])
	{
		if (ft_isspace(line[idx]))
			success = skip_space(&line[idx], &idx);
		else if (ft_isredirection(line[idx]))
			success = redirection_handler(units, &line[idx], &idx);
		else if (ft_ispipe(line[idx]))
			success = pipe_handler(units, &line[idx], &idx);
		else if (ft_isquote(line[idx]))
			success = quotes_handler(units, &line[idx], &idx);
		else 
			success = word_handler(units, &line[idx], &idx);
		if (!success)
			printf ("FAILURE IS FAILURE !\n"); //NOTE: alloc of node or content went wrong free and set units to null .
	}
}



static size_t redirection_handler(t_list **units, char *line, size_t *pos)
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
	listaddbacknode(units, node);
	idx += *pos;
	*pos = idx;
	return (idx);
}


static size_t pipe_handler(t_list **units, char *line, size_t *pos)
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
	listaddbacknode(units, node);
	idx += *pos;
	*pos = idx;
	return (idx);
}


static size_t quotes_handler(t_list **units, char *line, size_t *pos)
{
	t_list *node;
	size_t idx;
	char *content;
	t_metachar target;

	idx = 0;
	while (line[idx] && !ft_isunitbreaker(line[idx]))
	{
		target = line[idx];
		idx++;
		while ((t_metachar)line[idx] && (t_metachar)line[idx] != target)
			idx++;
		if (line[idx])
			idx++;
		while (line[idx] && !ft_isunitbreaker(line[idx]) && !ft_isquote(line[idx]))
			idx++;
	}
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
	listaddbacknode(units, node);
	idx += *pos;
	*pos = idx;
	return (idx);
}



static size_t word_handler(t_list **units, char *line, size_t *pos)
{
	t_list *node;
	size_t idx;
	char *content;
	t_metachar target;

	idx = 0;

	while (line[idx] && !ft_isunitbreaker(line[idx]))
	{
		if (ft_isquote(line[idx]))
		{
			target = line[idx];
			idx++;
			while (line[idx] && (t_metachar)line[idx] != target)
				idx++;
			if (line[idx])
				idx++;
		}
		else
			idx++;
	}
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
	listaddbacknode(units, node);
	idx += *pos;
	*pos = idx;
	return (idx);
}