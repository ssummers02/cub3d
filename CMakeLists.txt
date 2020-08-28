cmake_minimum_required(VERSION 3.12.3)
project(cub3d C)

set(CMAKE_C_STANDARD 99)


include_directories(SRCS)
include_directories(libft)
include_directories(opengl)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -L /Users/ssummers/CLionProjects/cub3d/opengl/ -lmlx -framework OpenGL -framework AppKit")

set(HEADER_FILES
        INCLUDES/get_next_line.h
        INCLUDES/libft.h
        opengl/mlx.h
        INCLUDES/cub.h)

set(SRC_FILES
        SRCS/ft_atoi.c
        SRCS/get_next_line.c
        SRCS/get_next_line_utils.c
        SRCS/ft_putstr_fd.c
        SRCS/ft_isdigit.c
        SRCS/ft_strncmp.c
        SRCS/ft_isalpha.c
        opengl/font.c
       # opengl/mlx_string_put.c
        SRCS/main.c
        SRCS/parser_help.c SRCS/help_func.c SRCS/init.c SRCS/parser_help2.c SRCS/checking.c SRCS/my_put_images.c)

add_executable(cub3d
        ${HEADER_FILES}
        ${SRC_FILES}
        )
