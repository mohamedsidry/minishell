
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
DEBUGMODE = 0
TESTUNIT = 0
SANITIZER = 0
EXTRAFLAGS = -fsanitize=address -g

ifeq ($(DEBUGMODE), 1)
	CFLAGS +=-DDEBUGMODE=1 
endif
ifeq ($(TESTUNIT), 1)
	CFLAGS += -DUNITTEST=1
endif
ifeq ($(SANITIZER), 1)
	CFLAGS += $(EXTRAFLAGS)
endif
# Sources Includes and Depandencies .

MAIN = main.c

UTILS = utils/general/nullstr.c  utils/general/ft_strcmp.c \
		utils/general/ft_trimspaces.c utils/general/ft_strchr.c \
		utils/general/ft_strlen.c utils/general/ft_strdup.c \
		utils/general/ft_strlcpy.c utils/general/ft_calloc.c \
		utils/general/ft_2dfree.c utils/general/ft_strncmp.c \
		utils/general/ft_strtrim.c utils/general/ft_isspace.c \
		utils/general/ft_stripspace.c utils/general/ft_trimbothends.c 
		
ENVSRCS =	utils/env/env_manager.c \
			utils/env/create_node.c \
			utils/env/delete_node.c \
			utils/env/read_node.c \
			utils/env/getvalue.c \
			utils/env/setvalue.c

PARSING = utils/parsing/proreadline.c utils/parsing/is_exit.c \
	  utils/parsing/parsing_handler.c

LINKEDLISTSRC = utils/linkedlist/listaddbacknode.c  \
				utils/linkedlist/listaddfrontnode.c \
				utils/linkedlist/listclearnodes.c \
				utils/linkedlist/listcreatenode.c \
				utils/linkedlist/listdeletenode.c \
				utils/linkedlist/listfindfirstnode.c \
				utils/linkedlist/listfindlastnode.c \
				utils/linkedlist/listiterate.c \
				utils/linkedlist/listprintnode.c \
				utils/linkedlist/listtrimnodecontent.c \
				utils/linkedlist/listsize.c


TEST = test/modenotifier.c test/run_unit_tests.c test/echo.c

SRCS = $(MAIN) $(UTILS) $(PARSING) $(LINKEDLISTSRC) $(ENVSRCS) $(TEST)

vpath %.h include
INCLUDES = header.h const.h error.h  test.h

DEPLIB = -lreadline


OBJS = $(SRCS:.c=.o)

%.o:%.c $(INCLUDES)
	@echo "\033[1;33m⚙️​ compiling :\033[0m\033[0;35m $< \033[0m"
	@$(CC) $(CFLAGS) $(CSTAGE) $< -o $@

$(NAME): $(OBJS) $(INCLUDES)
	@echo "\033[1;33m​🔗​​linking   :\033[0m\033[0;35m $@ \033[0m"
	@$(CC) $(CFLAGS) $^ $(DEPLIB) -o $@
	@echo "\033[1;33m🚀$(NAME) : \033[0mbuilding finished !"


clean:
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)

re: fclean all


all: $(NAME)

.PHONY: clean fclean re all debug run

run: clean $(NAME)
	@./$(NAME)

debug: 
	@make run DEBUGMODE=1 SANITIZER=1 TESTUNIT=1
	$(run)

vfrun: clean $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

runv: clean $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)


