##
## EPITECH PROJECT, 2018
## make
## File description:
## it makes files
##

MAIN =	src/main.c

SRC	=	src/read_file.c \
		src/make_map.c	\
		src/display_map.c 	\
		src/move_right_and_left.c \
		src/move_up_and_down.c 	\
		src/struct.c	\
		src/game_loop.c  \
		src/game_status.c	\
		src/check_map.c

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-I ./include -lncurses

TEST_NAME	=	soko_test

all:	$(NAME)

lib_make:
	@make -C lib/my

$(NAME):	$(OBJ)	lib_make
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) -L lib/my/ -lmy

clean:
	@rm -f $(OBJ)

fclean: clean
	@make -C lib/my clean
	@rm -f $(NAME)

debug:	lib_make
	@gcc -o $(NAME) $(MAIN) $(SRC) $(CFLAGS) -g3 -L lib/my/ -lmy
	@echo -e "\033[1;91mDebug mod enabled !\033[0;39m"

tests_run:	lib_make
	@echo -e "\033[1;95mRunning tests...\033[0;39m"
	@make -C lib/my
	@gcc -o $(TEST_NAME) $(SRC) -L lib/my/ -lmy --coverage -lcriterion
	./$(TEST_NAME)
	gcovr
	@echo -e "\033[1;94mTest finished, here are the results\033[0;39m"

re: fclean all
