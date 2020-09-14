SRCS			=	src/gnl/get_next_line.c src/gnl/get_next_line_utils.c \
					src/main.c src/game/parsing/make_map.c src/game/parsing/parsing.c \
					src/game/parsing/parsing_utils.c src/game/parsing/read_file.c \
					src/game/parsing/parsing_functions/parse_c.c src/game/parsing/parsing_functions/parse_ea.c \
					src/game/parsing/parsing_functions/parse_f.c \
					src/game/parsing/parsing_functions/parse_no.c src/game/parsing/parsing_functions/parse_r.c \
					src/game/parsing/parsing_functions/parse_s.c src/game/parsing/parsing_functions/parse_so.c \
					src/game/parsing/parsing_functions/parse_undefine_line.c \
					src/game/parsing/parsing_functions/parse_we.c src/game/parsing/parsing_functions/verify_map.c \
					src/game/parsing/parsing_functions/utils.c src/game/parsing/parsing_functions/parse_map.c \
					src/init.c src/game/draw/draw_circle.c src/game/managers/key_manager.c src/game/managers/loop_manager.c \
					src/game/draw/draw_utils.c src/game/managers/moving_asdw.c src/game/managers/windows_manager.c src/init2.c \
					src/game/draw/sprite_utils.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			=  -g -I .
#CFLAGS			= -g -Wall -Wextra -Werror -I .
#LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
#LIBS			= -L. -lft -L. -lmlx -framework OpenGL -framework AppKit -lm
LIBS			= -L. -lft -lmlx -lXext -lX11
LIBFT			= libft.a
HFILES			= src/game/game.h

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS) ${HFILES}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} -lm

$(LIBFT):
				@$(MAKE) -C src/libft
				@mv src/libft/$(LIBFT) .

%.o: %.c
	@echo "####       rebuild          ####"
	gcc $(CFLAGS) -o $@ -c $<

clean:
				@$(MAKE) -C src/libft clean
				$(RM) $(OBJS)