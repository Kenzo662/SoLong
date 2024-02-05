CC = gcc

CFLAGS = -Wall -Wextra -g3

NAME = so_long

SRCS = so_long.c checkmap.c init.c img.c movements.c movementsutils.c anim.c init2.c init3.c animstart.c imgutils.c

OBJ = $(SRCS:.c=.o)

all     :   $(NAME)

$(NAME) :   $(OBJ)
	$(MAKE) -C minilibx-linux
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./minilibx-linux/ -L./libft/ -lmlx -lXext -lX11 -lm -lft
clean   :
	$(MAKE) -C minilibx-linux clean
	$(MAKE) -C libft clean
	rm -rf $(OBJ)
fclean  :   clean
	rm -f $(NAME)
	
re      :   fclean all

.PHONY  :   clean fclean all re