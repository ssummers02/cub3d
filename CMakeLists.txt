cmake_minimum_required(VERSION 3.12.3)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(cub3d main.c)
#[[include_directories(sourse_file/get_next_line)
include_directories(sourse_file/libft)
include_directories(sourse_file/ft_printf)

set(HEADER_FILES
        source/get_next_line/get_next_line.h
        source/libft/libft.h
        source/ft_printf/libftprint.h
        )
set(SRC_FILES
        source/libft/ft_atoi.c
        source/get_next_line/get_next_line.c
        source/get_next_line/get_next_line_utils.c
        main.c source/libft/ft_atof.c)
add_executable(cub3d
        ${HEADER_FILES}
        ${SRC_FILES}
        )]]
