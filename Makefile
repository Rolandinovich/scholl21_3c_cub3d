SRCS			=	src/gnl/get_next_line.c src/gnl/get_next_line_utils.c \
					src/main.c src/game/parsing/make_map.c src/game/parsing/parsing.c \
					src/game/parsing/parsing_utils.c src/game/parsing/read_file.c \
					src/game/parsing/parsing_functions/parse_c.c src/game/parsing/parsing_functions/parse_ea.c \
					src/game/parsing/parsing_functions/parse_f.c src/game/parsing/parsing_functions/parse_f.c \
					src/game/parsing/parsing_functions/parse_no.c src/game/parsing/parsing_functions/parse_r.c \
					src/game/parsing/parsing_functions/parse_s.c src/game/parsing/parsing_functions/parse_so.c \
					src/game/parsing/parsing_functions/parse_undefine_line.c src/game/parsing/parsing_functions/parse_we.c \
					src/game/parsing/parsing_functions/parse_we.c src/game/parsing/parsing_functions/verify_map.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
#LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
LIBS			= -L. -lft
LIBFT			= libft.a
HFILES			= src/game/game.h src/gnl/get_next_line.h src/libft/libft.h

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS) ${HFILES}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(LIBFT):
				@$(MAKE) -C src/libft
				@mv src/libft/$(LIBFT) .

%.o: %.c
	@echo "####       rebuild          ####"
	gcc $(CFLAGS) -o $@ -c $<

clean:
				@$(MAKE) -C src/libft clean
				$(RM) $(OBJS)