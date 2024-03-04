##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC 	= 	gcc

CFLAGS = -Iinclude -W -Wall -Wextra -Wshadow -Werror

CHM     	=	source/
ARGS   		=	$(CHM)handle_args/
SOCKET		=	$(CHM)socket/
INPUT		=	$(CHM)handle_input/
CMD			=	$(CHM)handle_input/commands/
LIST		=	$(CHM)linked_lists/


SRC =	$(CHM)main.c 													\
		$(ARGS)check_args.c 											\
		$(ARGS)help_flag.c 												\
		$(SOCKET)create_socket.c 										\
		$(INPUT)parse_input.c 											\
		$(CMD)cdup_command.c 											\
		$(CMD)cwd_command.c 											\
		$(CMD)delete_command.c 											\
		$(CMD)help_command.c 											\
		$(CMD)list_command.c 											\
		$(CMD)noop_command.c 											\
		$(CMD)password_command.c 										\
		$(CMD)pasv_command.c 											\
		$(CMD)port_command.c 											\
		$(CMD)pwd_command.c 											\
		$(CMD)quit_command.c 											\
		$(CMD)retr_command.c 											\
		$(CMD)stor_command.c 											\
		$(CMD)user_command.c 											\
		$(LIST)list_add_begin.c 										\
		$(LIST)list_add_end.c 											\
		$(LIST)list_free.c												\
		$(LIST)list_is_empty.c											\
		$(LIST)list_add.c 												\
		$(LIST)list_len.c 												\
		$(LIST)list_print.c 											\

TEST = 		\

SRCTEST =	\

NAME =  myftp

NAMETEST =	unit_tests

OBJ =   $(SRC:%.c=%.o)

OBJTEST = $(SRCTEST:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@printf "\n\033[33m[Info]\033[39m Compilation done\n"

.c.o :
	@$(CC) $(CFLAGS) $(CFLAGS) -c $< -o $@
	@printf "\033[34m[Compilation]\033[39m %s\n" $<

tests_run	:	$(OBJTEST)
	@$(CC) $(OBJTEST) $(TEST) -o $(NAMETEST) -lcriterion

	@printf "\n\033[33m[Message]\033[39m Compilation of tests done\n"

clean :
	@$(RM) -f $(OBJ)
	@printf "\033[31m[Delete] \033[39m%s\n" $(OBJ)

fclean :	clean
	@$(RM) -f $(NAME)
	@$(RM) -f *.log
	@$(RM) -f *.o
	@$(RM) -f unit_tests
	@printf "\033[31m[Delete] \033[39m%s\n" $(NAME)

re: fclean all

debug:	CFLAGS += -g
debug:	re

run: re
	./$(NAME)

.PHONY 	= 	all clean fclean re
