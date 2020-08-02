cmake_minimum_required(VERSION 3.17)
project(scholl21_3c_cub3d C)

set(CMAKE_C_STANDARD 99)

add_executable(scholl21_3c_cub3d src/main.c src/parsing/parsing.h src/libft/libft.a src/gnl/get_next_line.c
       src/gnl/get_next_line_utils.c)