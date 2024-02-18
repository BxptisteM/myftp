##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC 	= 	gcc

CFLAGS = -Iinclude -W -Wall -Wextra -Wshadow -Werror

CHM     	=	source/

SRC =	$(CHM)main.c 													\

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