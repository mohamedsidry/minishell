
# Output executable name

NAME = minishell

# Compiling flags

CC = cc
CFLAGS = -Wall -Werror -Wextra
CSTAGE = -c

# Cleaning flags

RM = rm
RMFLAGS = -fr

# Debug and testing flags

EXTRAFLAGS = -fsanitize=address -g


# Sources Includes and Depandencies .
 

MAIN = main.c

UTILS = utils/general/nullstr.c  utils/general/ft_strcmp.c \
	utils/general/ft_trimspaces.c utils/general/ft_strdup.c \
	utils/general/ft_strlcpy.c utils/general/ft_strlen.c \
	utils/general/ft_isspace.c

PARSING = utils/parsing/proreadline.c utils/parsing/is_exit.c

SRCS = $(MAIN) $(UTILS) $(PARSING)

vpath %.h include
INCLUDES = header.h const.h error.h 

DEPLIB = -lreadline


OBJS = $(SRCS:.c=.o)

%.o:%.c $(INCLUDES)
	@echo "\033[1;33mCompiling\033[0m\033[1;35m $< \033[0m"
	@$(CC) $(CFLAGS) $(CSTAGE) $< -o $@

$(NAME): $(OBJS) $(INCLUDES)
	@$(CC) $(CFLAGS) $^ $(DEPLIB) -o $@


clean:
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)

re: fclean all


all: $(NAME)

.PHONY: clean
