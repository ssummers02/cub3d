NAME = cub3d
HEADERS = cub.h
CFLAGS = -Wall -Werror -Wextra

SRC = main.c help_func.c\
             init.c\
             parser_help.c\
             parser_help2.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C libft all
		$(MAKE) -C minilibx
		gcc $(OBJ) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADERS)
		$(CC) -Imlx -c $< -o $@

clean:
		rm -f $(OBJ)
			$(MAKE) -C libft clean

fclean:	clean
		$(MAKE) -C libft fclean
			rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
