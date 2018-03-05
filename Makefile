CC =            gcc
NAME =          solve
SRC =           *.c

CFLAGS =        -W -Wall -Wextra -Werror
OBJ =           $(SRC:%.c=%.o)
RM =            rm

$(NAME) :	$(OBJ)
		$(CC) $(SRC) $(CFLAGS) -o $(NAME)
		rm *.o

all:		$(NAME)
clean:
		$(RM) $(OBJ)

fclean:		clean