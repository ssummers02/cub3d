NAME=libftprintf.a

FILES=print_other \
      ft_strndup \
      ft_isdigit \
      parse \
      print_o \
      ft_strcmp \
      ft_strjoin \
      ft_printf \
      initializing \
      print_p \
      ft_bzero \
      print_s \
      print_d \
      print_x \
      print_f \
      print_check \
      ft_strdup \
      ft_memset \
      ft_strchr \
      ft_s_toupper \
      add_z \
      nb_max \
      check_all_flag \
      checker \
      print_u \
      ft_strlen \
      print_c \
      ft_all_nbr \
      ft_all_put \
      ft_all_toa \
      ft_intlen_max \

OBJECTS = $(SRCS:.c=.o)

INCLUDES=./
CC = @gcc
FLAGS = -I$(INCLUDES) -Wall -Wextra -Werror

FILES.C = $(addprefix $(INCLUDES), $(FILES:=.c))
FILES.O = $(addprefix $(INCLUDES), $(FILES:=.o))


.PHONY : all clean fclean re bonus

all: $(NAME) $(FILES.C)
$(NAME): $(FILES.O)
	@ar rc $(NAME) $(FILES.O)
	@ranlib $(NAME)

$(FILES.O): $(INCLUDES)%.o: $(INCLUDES)%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: all

