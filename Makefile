
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
		utils/general/ft_stripspace.c utils/general/ft_trimbothends.c \
		utils/general/ft_joinstrs.c utils/general/ft_concatenate.c \
		utils/general/ft_ispipe.c utils/general/ft_isquote.c \
		utils/general/ft_isredirection.c utils/general/ft_isunitbreaker.c \
		utils/general/skip_space.c utils/general/ft_ismetachar.c \
		utils/general/ft_isampersand.c utils/general/ft_issemicolon.c \
		utils/general/ft_startwith.c utils/general/ft_itoa.c \
		utils/general/ft_strstr.c
		
ENVSRCS =	utils/env/env_manager.c \
			utils/env/create_node.c \
			utils/env/delete_node.c \
			utils/env/read_node.c \
			utils/env/getvalue.c \
			utils/env/setvalue.c \
			utils/env/env_serializer.c \
			utils/env/update_node.c 

PARSING =	utils/parsing/proreadline.c utils/parsing/is_exit.c \
	  		utils/parsing/parsing_handler.c utils/parsing/lexer.c

VALIDATION = utils/validation/validator.c \
			 utils/validation/quotes.c \
			 utils/validation/supported.c \
			 utils/validation/syntax.c \
			 utils/validation/expanding.c

COMMANDSRC = utils/command/serializer.c \
			 utils/command/command_manager.c \
			 utils/command/create_command.c \
			 utils/command/delete_command.c \
			 utils/command/read_command.c \
			 utils/command/update_command.c 

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
				utils/linkedlist/listsize.c \
				utils/linkedlist/listvalidatenode.c \
				utils/linkedlist/listmap.c \
				utils/linkedlist/listnodedup.c \
				utils/linkedlist/listclearcommands.c


TEST =	test/test.c test/modenotifier.c test/run_unit_tests.c \
		test/echo.c test/print_arr.c test/display_env.c \
		test/display_tokens.c test/display_commands.c


SRCS = $(MAIN) $(UTILS) $(PARSING) $(LINKEDLISTSRC) $(ENVSRCS) $(VALIDATION) $(COMMANDSRC) $(TEST)

vpath %.h include
INCLUDES = header.h const.h error.h  test.h typedef.h utils.h

# LIB FOR READLINE and addhitory functions !

DEPLIB = -lreadline


OBJS = $(SRCS:.c=.o)

%.o:%.c $(INCLUDES)
	@echo "\033[1;33m⚙️​ compiling :\033[0m\033[0;35m $< \033[0m"
	@$(CC) $(CFLAGS) $(CSTAGE) $< -o $@

$(NAME): $(OBJS)
	@echo "\033[1;33m​🔗​​linking   :\033[0m\033[0;35m $@ \033[0m"
	@$(CC) $(CFLAGS) $(DEPLIB) $(OBJS) -o $@
	@echo "\033[1;33m🚀$(NAME) : \033[0mbuilding finished !"


clean:
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)

re: fclean all


all: $(NAME)

.PHONY: clean fclean re all debug run

run: $(NAME) clean
	@./$(NAME)

debug:  
	@make run DEBUGMODE=1 SANITIZER=1 TESTUNIT=1

fvrun: clean $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

vrun: clean $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)


norms:
	@echo $(CHECKINGNORMS)
	@norminette | grep 'Error!' && echo $(KO) || echo $(OK)

CHECKINGNORMS = "\033[1;33mNorminette ...\033[0m"


OK="\033[1;32mNorminette OK!\033[0m"
KO="\033[1;31mNorminette KO!\033[0m"