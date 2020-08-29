NAME = cub3d
HEADERS = ./INCLUDES/cub.h\
		./INCLUDES/get_next_line.h\
		./INCLUDES/libft.h
CFLAGS =

SRC =  SRCS/ft_atoi.c\
              SRCS/get_next_line.c\
              SRCS/get_next_line_utils.c\
              SRCS/ft_putstr_fd.c\
              SRCS/ft_isdigit.c\
              SRCS/ft_strncmp.c\
              SRCS/ft_isalpha.c\
              SRCS/main.c\
               SRCS/my_put_images.c\
              SRCS/parser_help.c SRCS/help_func.c SRCS/init.c SRCS/parser_help2.c SRCS/checking.c


OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./opengl
	gcc $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
#	$(MAKE) -C ./minilibx clean


re:		fclean all

.PHONY: all clean fclean re