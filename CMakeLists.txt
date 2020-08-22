cmake_minimum_required(VERSION 3.12.3)
project(cub3d C)

set(CMAKE_C_STANDARD 99)


include_directories(source/get_next_line)
include_directories(libft)
include_directories(source/ft_printf)
include_directories(minilibx)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -L /Users/ssummers/CLionProjects/cub3d/minilibx/ -lmlx -framework OpenGL -framework AppKit -O3")

set(HEADER_FILES
        source/get_next_line/get_next_line.h
        libft/libft.h
        source/ft_printf/libftprint.h
        minilibx/mlx.h
        cub.h)

set(SRC_FILES
        libft/ft_atoi.c
        source/get_next_line/get_next_line.c
        source/get_next_line/get_next_line_utils.c
        libft/ft_putstr_fd.c
        libft/ft_isdigit.c
        libft/ft_strncmp.c
        libft/ft_isalpha.c
        minilibx/font.c
        minilibx/mlx_string_put.c
        main.c
        parser_help.c help_func.c init.c parser_help2.c)

add_executable(cub3d
        ${HEADER_FILES}
        ${SRC_FILES}
        )
