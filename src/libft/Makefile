CFILES=ft_atoi.c \
       ft_isascii.c \
       ft_memchr.c \
       ft_memset.c \
       ft_strlen.c \
       ft_tolower.c \
       ft_bzero.c \
       ft_isdigit.c \
       ft_memcmp.c \
       ft_strchr.c \
       ft_strncmp.c \
       ft_toupper.c \
       ft_isalnum.c \
       ft_isprint.c \
       ft_memcpy.c \
       ft_strlcat.c \
       ft_strnstr.c \
       ft_isalpha.c \
       ft_memccpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strrchr.c \
       ft_calloc.c \
       ft_strdup.c \
       ft_strjoin.c \
       ft_substr.c \
       ft_strtrim.c \
       ft_split.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c

CFILES_BONUS=  ft_lstnew.c \
			   ft_lstadd_front.c \
			   ft_lstsize.c \
			   ft_lstlast.c \
			   ft_lstadd_back.c \
			   ft_lstdelone.c \
			   ft_lstclear.c \
			   ft_lstiter.c \
			   ft_lstmap.c

OFILES=ft_atoi.o \
       ft_isascii.o \
       ft_memchr.o \
       ft_memset.o \
       ft_strlen.o \
       ft_tolower.o \
       ft_bzero.o \
       ft_isdigit.o \
       ft_memcmp.o \
       ft_strchr.o \
       ft_strncmp.o \
       ft_toupper.o \
       ft_isalnum.o \
       ft_isprint.o \
       ft_memcpy.o \
       ft_strlcat.o \
       ft_strnstr.o \
       ft_isalpha.o \
       ft_memccpy.o \
       ft_memmove.o \
       ft_strlcpy.o \
       ft_strrchr.o \
       ft_calloc.o \
       ft_strdup.o \
       ft_strjoin.o \
       ft_substr.o \
       ft_strtrim.o \
       ft_split.o \
       ft_itoa.o \
       ft_strmapi.o \
       ft_putchar_fd.o \
       ft_putstr_fd.o \
       ft_putendl_fd.o \
       ft_putnbr_fd.o

OFILES_BONUS=  ft_lstnew.o \
			   ft_lstadd_front.o \
			   ft_lstsize.o \
			   ft_lstlast.o \
			   ft_lstadd_back.o \
			   ft_lstdelone.o \
			   ft_lstclear.o \
			   ft_lstiter.o \
			   ft_lstmap.o
       
HFILES=libft.h

NAME=libft.a

CFLAGS=-Wall -Werror -Wextra -c

all: $(NAME)

$(NAME): $(OFILES) $(HFILES)
	@ar rcs $(NAME) $(OFILES)
	@echo "####   I & II PART CREATED  ####"
	@ranlib $(NAME)

bonus: $(OFILES_BONUS) $(HFILES)
	@ar rcs $(NAME)  $(OFILES_BONUS)
	@echo "####   BONUS PART CREATED   ####"
	@ranlib $(NAME)

%.o: %.c
	@echo "####       rebuild          ####"
	gcc $(FLAGS) -o $@ -c $<

so: 
	gcc -fPIC -c $(CFILES) $(CFILES_BONUS) -H $(HFILES)
	rm -f libft.so
	gcc -shared -o libft.so $(OFILES) $(OFILES_BONUS)

clean:
	rm -f $(OFILES) $(OFILES_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all