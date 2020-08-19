cmake_minimum_required(VERSION 3.12.3)
project(cub3d C)

set(CMAKE_C_STANDARD 99)


include_directories(source/get_next_line)
include_directories(source/libft)
include_directories(source/ft_printf)

set(HEADER_FILES
        source/get_next_line/get_next_line.h
        source/libft/libft.h
        source/ft_printf/libftprint.h
        cub.h)

set(SRC_FILES
        source/libft/ft_atoi.c
        source/get_next_line/get_next_line.c
        source/get_next_line/get_next_line_utils.c
        source/libft/ft_putstr_fd.c
        source/libft/ft_isdigit.c
        source/libft/ft_strncmp.c
        source/libft/ft_isalpha.c
        main.c
        parser_help.c help_func.c init.c parser_help2.c)

add_executable(cub3d
        ${HEADER_FILES}
        ${SRC_FILES}
        )