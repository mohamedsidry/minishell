#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef enum e_metachar
{
	_SPACE = ' ',
	_METATAB = '\t',
	_NEWLINE = '\n',
	PIPE = '|',
	REDIRECT_IN = '<',
	REDIRECT_OUT = '>',
	ANDCHAR = '&',
	O_PARANTHESES = '(',
	C_PARANTHESES = ')',
	S_QUOTE = '\'',
	D_QUOTE = '"',
	SEMICOLON = ';',
	BACKSLASH = '\\',

} t_metachar;

typedef enum s_token
{
	WORD,
	REDIRECTION,
	APPEND,
	HEREDOC,
	COMMAND,
	COMMANDARG,
} t_token;

typedef enum s_action
{
	CREATE = 1,
	READ = 2,
	UPDATE = 4,
	DELETE = 8,

} t_action;

typedef struct s_list
{
    void *content;
    t_token token;
    struct s_list *next;
    struct s_list *prev;
} t_list;

typedef struct s_command
{
	char *exe;

} t_command;


typedef struct s_envnode
{
	char *key;
	char *value;
} t_envnode;
#endif // TYPEDEF_H
