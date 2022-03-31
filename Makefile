# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bterral <bterral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 14:42:02 by bterral           #+#    #+#              #
#    Updated: 2022/03/31 16:42:36 by bterral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

FFLAGS			= -fsanitize=address -g

NAME			= minishell

HEADER			= ./includes/minishell.h

SRC				= main.c

SRC_ALLOC		= alloc_mem/ft_free.c

SRC_PARSING		= parsing/dollar.c parsing/quote.c parsing/parsing.c parsing/parsing_utils.c \
					parsing/quote2.c

SRC_PRINT		= print/print.c

SRC_VAR_ENV		= ./srcs/environment_variables/environment.c \
					./srcs/environment_variables/environment_utils.c

OBJS			= $(SRC:.c=.o) $(SRC_ALLOC:.c=.o) $(SRC_PARSING:.c=.o) \
					 $(SRC_PRINT:.c=.o) $(SRC_VAR_ENV:.c=.o)

#OBJD			= ./objs/

#OBJS			= $(addprefix $(OBJD), $(OBJ_FILES))

LIBFT			= ./libft/libft.a

all: $(NAME)

%.o: %.c libft $(HEADER)
	$(CC) $(CFLAGS) $(FFLAGS) -c $< -o $@ -I ./includes

$(NAME): $(OBJS) $(HEADER) Makefile
	${CC} $(CFLAGS) $(FFLAGS) -lreadline $(OBJS) $(LIBFT) -o $(NAME)

libft:
	$(MAKE) -C ./libft

clean:
	make clean -C ./libft
	rm -rf ${OBJS}

fclean: clean
	make fclean -C ./libft
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean libft re
