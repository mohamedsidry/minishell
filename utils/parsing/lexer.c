#include "../../include/header.h"

static size_t redirection_handler(t_list **tokens, char *line, size_t *pos);
static size_t pipe_handler(t_list **tokens, char *line, size_t *pos);
static size_t quotes_handler(t_list **tokens, char *line, size_t *pos);
static size_t word_handler(t_list **tokens, char *line, size_t *pos);
static size_t ampersands_handler(t_list **tokens, char *line, size_t *pos);
static size_t metachar_handler(t_list **tokens, char *line, size_t *pos);
static size_t semicolon_hanndler(t_list **tokens, char *line, size_t *pos);

static t_token context_guarder(char *current, int dflt);
static t_token meta_map_context(char *current, t_jobcontext *nextcontext);
static t_token other_map_context(char *current, t_jobcontext *nextcontext);

void lexer(t_list **tokens, char *line)
{
	size_t idx;
	size_t result;

	idx = 0;
	if (!tokens || !line)
		return ;
	context_guarder(line, 0); // NOTE: save prev token state a.k.a "type" of prev token ! 0 just a flag to reset it each time we parce a new str !
	while (line[idx])
	{
		if (ft_ismetachar(line[idx]))
			result = metachar_handler(tokens, &line[idx], &idx);
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

static size_t metachar_handler(t_list **tokens, char *line, size_t *pos)
{
	size_t result;
	// NOTE: metachar are char that separate tokens if they are not quoted 
	// example : |, <, &, ;,  \n, \t, space, ... 

	result = 0;
	if (!line)
		return (0);
	else if (ft_isspace(*line))
		result = skip_space(line, pos);
	else if (ft_ispipe(*line))
		result = pipe_handler(tokens, line, pos);
	else if (ft_isredirection(*line))
		result = redirection_handler(tokens, line, pos);
	else if (ft_isampersand(*line))
		result = ampersands_handler(tokens, line, pos);
	else if (ft_issemicolon(*line))
		result = semicolon_hanndler(tokens, line, pos);
	return (result);
}


static size_t semicolon_hanndler(t_list **tokens, char *line, size_t *pos)
{
	t_list *node;
	size_t idx;
	char *content;

	idx = 1;
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
	node->type = context_guarder(content, 1);
	listaddbacknode(tokens, node);
	*pos += idx;
	return (SUCCESS);
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
	node->type = context_guarder(content, 1);
	listaddbacknode(tokens, node);
	if (line[0] == CHAR_REDIRECT_OUT && (line[1] == CHAR_AMPERSAND || line[1] == CHAR_PIPE))
		idx++; //TODO: handles case of ls -la>|out 
			   //NOTE: it should not give error it should skip that | OR &
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
	node->type = context_guarder(content, 1);
	listaddbacknode(tokens, node);
	if (line[1] == CHAR_AMPERSAND)
		idx++;
	*pos += idx;
	return (SUCCESS);
}

static size_t ampersands_handler(t_list **tokens, char *line, size_t *pos)
{
	t_list *node;
	size_t idx;
	char *content;

	idx = 1;
	if (line[0] == line[1])
		idx++;
	if (line[1] == CHAR_REDIRECT_OUT)
	{
		*pos += idx; //NOTE: if &> just skip & !
		return (SUCCESS);
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
	node->type = context_guarder(content, 1);
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
	while (line[idx] && !ft_ismetachar(line[idx]))
	{
		target = line[idx];
		idx++;
		while ((t_metachar)line[idx] && (t_metachar)line[idx] != target)
			idx++;
		if (line[idx])
			idx++;
		while (line[idx] && !ft_ismetachar(line[idx]) && !ft_isquote(line[idx]))
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
	node->type = context_guarder(content, 1);
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

	while (line[idx] && !ft_ismetachar(line[idx]))
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
	node->type = context_guarder(content, 1);
	listaddbacknode(tokens, node);
	*pos += idx;
	return (SUCCESS);
}

static t_token context_guarder(char *current, int deff)
{
	static t_jobcontext nextcontext;
	t_token token;
	token = 1;
	if (deff == 0)
		return(nextcontext = DEFAULT, token);
	if (ft_ismetachar(*current))
		token = meta_map_context(current, &nextcontext);
	else
		token = other_map_context(current, &nextcontext);
	return (token);
}

static t_token meta_map_context(char *current, t_jobcontext *nextcontext)
{
	if (!ft_strcmp(current, STR_PIPE))
		return (*nextcontext = DEFAULT, PIPE);
	else if (!ft_strcmp(current, STR_AMPERSAND))
		return (*nextcontext = DEFAULT, RUNBACKGROUND);
	else if (!ft_strcmp(current, STR_AND))
		return (*nextcontext = DEFAULT, AND);
	else if (!ft_strcmp(current, STR_OR))
		return (*nextcontext = DEFAULT, OR);
	else if (!ft_strcmp(current, STR_SEMICOLON))
		return (*nextcontext = DEFAULT, SEQUENCE);
	else if (!ft_strcmp(current, STR_RE_IN))
		return (*nextcontext = INFILE, REDIRECT_IN);
	else if (!ft_strcmp(current, STR_RE_OUT))
		return (*nextcontext = OUTFILE, REDIRECT_OUT);
	else if (!ft_strcmp(current, STR_APPEND))
		return (*nextcontext = OUTFILE, APPEND);
	else if (!ft_strcmp(current, STR_HEREDOC))
		return (*nextcontext = LIMIT, APPEND);
	return (*nextcontext = DEFAULT, COMMAND);
}


static t_token other_map_context(char *current, t_jobcontext *nextcontext)
{
	t_jobcontext prev;
	(void)current;
	prev = *nextcontext;
	if (prev == DEFAULT)
		return (*nextcontext = CMD, COMMAND);
	else if (prev == INFILE)
		return (*nextcontext = CMD, FILE_IN);
	else if (prev == OUTFILE)
		return (*nextcontext = CMD, FILE_OUT);
	else if (prev == LIMIT)
		return (*nextcontext = CMD, LIMITER);
	else
		return (COMMAND);
}
