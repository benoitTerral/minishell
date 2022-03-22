CC= gcc
CFLAGS= -Wall -Wextra -Werror
FFLAGS= -fsanitize=address -g
NAME= minishell
SRC= main.c
SRC_ALLOC= alloc_mem/ft_free.c
SRC_PARSING= parsing/dollar.c parsing/quote.c parsing/parsing.c
SRC_PRINT= print/print.c
SRCLIB= libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memmove.c libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_isalpha.c libft/ft_memchr.c libft/ft_memset.c libft/ft_strlcpy.c libft/ft_strrchr.c libft/ft_bzero.c libft/ft_isascii.c libft/ft_memcmp.c libft/ft_strchr.c libft/ft_strlen.c libft/ft_tolower.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_strdup.c libft/ft_strncmp.c libft/ft_toupper.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/get_next_line.c
HDR= minishell.h libft/libft.h libft/get_next_line.h parsing/parsing.h print/print.h alloc_mem/alloc_mem.h
OBJ= ${SRC:.c=.o} ${SRC_ALLOC:.c=.o} ${SRC_PARSING:.c=.o} ${SRC_PRINT:.c=.o}
LIB= libft/libft.a

all: ${NAME}

%.o: %.c ${HDR}
	${CC} ${CFLAGS} ${FFLAGS} -c $< -o $@ -I./headers

${NAME}: ${OBJ} ${SRCLIB} ${HDR} Makefile
	make all -C ./libft
	${CC} ${CFLAGS} ${FFLAGS} ${OBJ} ${LIB} -o ${NAME}

clean:
	make clean -C ./libft
	rm -rf ${OBJ}

fclean: clean
	make fclean -C ./libft
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re