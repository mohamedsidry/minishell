#ifndef CONST_H
# define CONST_H

# define FAILURE 1
# define SUCCESS 0
# define VALID 1
# define NONVALID 0
# ifndef DEBUGMODE
# define DEBUGMODE 0
# endif // DEBUGMODE
# ifndef NAME
#  define NAME "minishell"
# endif // NAME
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
# define STR_RE_OUT ">" //NOTE: ">|" is valid forecreate but we don't need to handle it  .
# define STR_AND "&&"
# define STR_AMPERSAND "&" //NOTE: "&>" is valid but we dont need to handle redirect stdin and stdout .
# define STR_PIPEAND "|&" //NOTE: no need for it since we dont handle redirect stderr .
# define STR_OR "||"
# define STR_HEREDOC "<<"
# define STR_APPEND ">>"
# define STR_SEMICOLON ";"

#ifndef SUCCESS
# define SUCCESS 1
#endif

#ifndef FAILURE
# define FAILURE 0
#endif

#endif // CONST_H
