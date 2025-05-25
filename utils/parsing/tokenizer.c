#include "../../include/header.h"

static size_t redirection_handler(t_list **tokens, char *line, size_t *pos);
static size_t pipe_handler(t_list **tokens, char *line, size_t *pos);
static size_t quotes_handler(t_list **tokens, char *line, size_t *pos);
static size_t word_handler(t_list **tokens, char *line, size_t *pos);

void tokenizer(t_list **tokens, char *line)
{
	size_t idx;
	size_t result;

	idx = 0;
	if (!tokens || !line)
		return ;
	while (line[idx])
	{
		if (ft_isspace(line[idx]))
			result = skip_space(&line[idx], &idx);
		else if (ft_isredirection(line[idx]))
			result = redirection_handler(tokens, &line[idx], &idx);
		else if (ft_ispipe(line[idx]))
			result = pipe_handler(tokens, &line[idx], &idx);
		else if (ft_isquote(line[idx]))
			result = quotes_handler(tokens, &line[idx], &idx);
		else 
			result = word_handler(tokens, &line[idx], &idx);
		if (result == FAILURE)
		{
			listclearnodes(tokens, listdeletenode);
			write(2, ERRTOKEN, ft_strlen(ERRTOKEN));
			return ;
		}	
	}
}



static size_t redirection_handler(t_list **tokens, char *line, size_t *pos)
{
	t_list *node;
	size_t idx;
	char *content;

	idx = 1;
	if (line[0] == line[1])
		idx++;
	content = ft_calloc(idx + 1, sizeof(char));
	if (!content)
		return (FAILURE);
	ft_strlcpy(content, line, idx + 1);
	node = listcreatenode(content);
	if (!node)
	{
		nullstr(&content);
		return(FAILURE);
	}
	listaddbacknode(tokens, node);
	*pos += idx;
	return (SUCCESS);
}


static size_t pipe_handler(t_list **tokens, char *line, size_t *pos)
{
	t_list *node;
	size_t idx;
	char *content;

	idx = 1;
	if (line[0] == line[1])
		idx++;
	content = ft_calloc(idx + 1, sizeof(char));
	if (!content)
		return (FAILURE);
	ft_strlcpy(content, line, idx + 1);
	node = listcreatenode(content);
	if (!node)
	{
		nullstr(&content);
		return(FAILURE);
	}
	listaddbacknode(tokens, node);
	*pos += idx;
	return (SUCCESS);
}


static size_t quotes_handler(t_list **tokens, char *line, size_t *pos)
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
		return (FAILURE);
	ft_strlcpy(content, line, idx + 1);
	node = listcreatenode(content);
	if (!node)
	{
		nullstr(&content);
		return(FAILURE);
	}
	listaddbacknode(tokens, node);
	*pos += idx;
	return (SUCCESS);
}



static size_t word_handler(t_list **tokens, char *line, size_t *pos)
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
		return (FAILURE);
	ft_strlcpy(content, line, idx + 1);
	node = listcreatenode(content);
	if (!node)
	{
		nullstr(&content);
		return(FAILURE);
	}
	listaddbacknode(tokens, node);
	*pos += idx;
	return (SUCCESS);
}
