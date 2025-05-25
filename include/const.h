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

#endif // CONST_H
