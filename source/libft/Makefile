NAME=libft.a

FILES=ft_atoi       ft_bzero   ft_isalnum ft_isalpha ft_isascii \
	 ft_isprint    ft_memccpy ft_memchr  ft_memcmp  ft_memcpy   \
   	 ft_memset     ft_strchr  ft_strdup  ft_strlcat ft_strlcpy  \
	 ft_putnbr_fd  ft_strncmp ft_strnstr ft_strrchr ft_tolower  \
	 ft_putstr_fd  ft_calloc  ft_substr  ft_strjoin ft_strtrim  \
	 ft_putendl_fd ft_strmapi ft_split   ft_toupper ft_memmove  \
	 ft_putchar_fd ft_isdigit ft_itoa    ft_strlen
BONUS = ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter \
        ft_lstlast ft_lstmap ft_lstnew ft_lstsize

OBJECTS = $(SRCS:.c=.o)

INCLUDES=./
CC = gcc
FLAGS = -I$(INCLUDES) -Wall -Wextra -Werror

FILES.C = $(addprefix $(INCLUDES), $(FILES:=.c))
FILES.O = $(addprefix $(INCLUDES), $(FILES:=.o))
BONUS.O = $(addprefix $(INCLUDES), $(BONUS:=.o))
BONUS.C = $(addprefix $(INCLUDES), $(BONUS:=.c))

.PHONY : all clean fclean re bonus

all: $(NAME) $(FILES.C)

$(NAME): $(FILES.O)
	ar rc $(NAME) $(FILES.O)
	ranlib $(NAME)

$(FILES.O): $(INCLUDES)%.o: $(INCLUDES)%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: $(BONUS.O) $(BONUS.C)
	ar rc $(NAME) $(BONUS.O)
	ranlib $(NAME)

$(BONUS.O):$(INCLUDES)%.o: $(INCLUDES)%.c
	$(CC) $(FLAGS) -c $< -o $@
