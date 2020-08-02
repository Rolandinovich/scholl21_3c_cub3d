cmake_minimum_required(VERSION 3.17)
project(scholl21_3c_cub3d C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_library(libft STATIC src/libft/ft_atoi.c src/libft/ft_isascii.c src/libft/ft_memchr.c src/libft/ft_memset.c src/libft/ft_strlen.c src/libft/ft_tolower.c src/libft/ft_bzero.c
        src/libft/ft_isdigit.c src/libft/ft_memcmp.c src/libft/ft_strchr.c src/libft/ft_strncmp.c src/libft/ft_toupper.c src/libft/ft_isalnum.c src/libft/ft_isprint.c src/libft/ft_memcpy.c src/libft/ft_strlcat.c src/libft/ft_strnstr.c
        src/libft/ft_isalpha.c
        src/libft/ft_memccpy.c
        src/libft/ft_memmove.c
        src/libft/ft_strlcpy.c
        src/libft/ft_strrchr.c
        src/libft/ft_calloc.c
        src/libft/ft_strdup.c
        src/libft/ft_strjoin.c
        src/libft/ft_substr.c
        src/libft/ft_strtrim.c
        src/libft/ft_split.c
        src/libft/ft_itoa.c
        src/libft/ft_strmapi.c
        src/libft/ft_putchar_fd.c
        src/libft/ft_putstr_fd.c
        src/libft/ft_putendl_fd.c
        src/libft/ft_putnbr_fd.c)

add_executable(scholl21_3c_cub3d src/main.c src/gnl/get_next_line.c src/gnl/get_next_line_utils.c src/libft/libft.a)
target_link_libraries(scholl21_3c_cub3d libft)