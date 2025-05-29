#ifndef CONST_H
# define CONST_H

# define FAILURE 1
# define SUCCESS 0
# ifndef DEBUGMODE
# define DEBUGMODE 0
# endif // DEBUGMODE

# ifndef PROMPT
#  define PROMPT "\033[1;32mminishell $> \033[0m"
# endif // PROMPT

# define EXITCMD "exit"
# define PWD "PWD"
# define PATH "PATH"
# define SHLVL "SHLVL"


// OPERATORES 

# define STR_PIPE "|"
# define STR_RE_IN "<"
# define STR_RE_OUT ">"
# define STR_AND "&&"
# define STR_AMPERSAND "&"
# define STR_PIPEAND "|&"
# define STR_OR "||"
# define STR_HEREDOC "<<"
# define STR_APPEND ">>"
# define STR_SEMICOLON ";"

#endif // CONST_H
