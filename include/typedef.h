#ifndef TYPEDEF_H
# define TYPEDEF_H

# include <stdio.h> // added this to remove later 

typedef enum e_metachar
{
	CHAR_SPACE = ' ',
	CHAR_TAB = '\t',
	CHAR_NEWLINE = '\n',
	CHAR_PIPE = '|',
	CHAR_REDIRECT_IN = '<',
	CHAR_REDIRECT_OUT = '>',
	CHAR_AMPERSAND = '&',
	CHAR_OPARANTHESES = '(',
	CHAR_CPARANTHESES = ')',
	CHAR_SQUOTE = '\'',
	CHAR_DQUOTE = '"',
	CHAR_SEMICOLON = ';',
	CHAR_BACKSLASH = '\\',
	CHAR_BACKTICK = '`',
	CHAR_HYPHEN = '-',
	CHAR_DOLLAR = '$',

} t_metachar;

typedef enum s_token
{
	COMMAND = 1,
	ARG,
	FILE_IN,
	FILE_OUT,
	REDIRECT_IN,
	REDIRECT_OUT,
	FILE_APPEND,
	APPEND,
	HEREDOC,
	LIMITER,
	PIPE,
	AND,
	OR,
	RUNBACKGROUND,
	PIPEAND,
	SEQUENCE, //sequence
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
    t_token type;
    struct s_list *next;
    struct s_list *prev;
} t_list;

typedef struct s_envnode
{
	char *key;
	char *value;
} t_envnode;

typedef struct s_command
{
	char *executable;
	size_t pid;
	int runinbackground;
	int waitforit;
	t_list *args;
	t_list *infiles;
	t_list *outfiles;
	t_list *appendfiles;
	t_list *limiters;
	int pipe[2];
} t_command;

//typedef struct
#endif // TYPEDEF_H
