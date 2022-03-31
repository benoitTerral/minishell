# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bterral <bterral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 14:42:02 by bterral           #+#    #+#              #
#    Updated: 2022/03/31 14:52:28 by bterral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

FFLAGS			= -fsanitize=address -g

NAME			= minishell

headers			= ./includes

SRC				= main.c

SRC_ALLOC		= alloc_mem/ft_free.c

SRC_PARSING		= parsing/dollar.c parsing/quote.c parsing/parsing.c parsing/parsing_utils.c \
					parsing/quote2.c

SRC_PRINT		= print/print.c

SRC_VAR_ENV		= ./srcs/environment_variables/environment.c \
					./srcs/environment_variables/environment_variables.c

OBJ				= ${SRC:.c=.o} ${SRC_ALLOC:.c=.o} ${SRC_PARSING:.c=.o} \
					 ${SRC_PRINT:.c=.o} ${SRC_VAR_ENV=.c=.o}

all: ${NAME}

%.o: %.c ${HDR}
	${CC} ${CFLAGS} ${FFLAGS} -c $< -o $@ -I./headers

${NAME}: ${OBJ} ${SRCLIB} ${HDR} Makefile
	make all -C ./libft
	${CC} ${CFLAGS} ${FFLAGS} -lreadline ${OBJ} ${LIB} -o ${NAME}

clean:
	make clean -C ./libft
	rm -rf ${OBJ}

fclean: clean
	make fclean -C ./libft
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re