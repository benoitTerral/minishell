# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bterral <bterral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 14:42:02 by bterral           #+#    #+#              #
#    Updated: 2022/05/25 10:19:46 by bterral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

#FFLAGS			= -fsanitize=address -g

NAME			= minishell

HEADER			= ./includes/minishell.h parsing/parsing.h \
					print/print.h alloc_mem/alloc_mem.h \
					lexer/lexer.h

#HDR= libft/libft.h libft/get_next_line.h parsing/parsing.h print/print.h alloc_mem/alloc_mem.h lexer/lexer.h

RL_LIB			= -L ~/.brew/opt/readline/lib
RL_INC			= -I ~/.brew/opt/readline/include

SRC				= main.c

SRC_ALLOC		= alloc_mem/ft_free.c

SRC_LEXER		= lexer/lexer.c lexer/lst.c lexer/listdup_token.c

SRC_PARSING		= parsing/dollar.c parsing/quote.c parsing/parsing.c parsing/parsing_utils.c \
					parsing/quote2.c parsing/operator.c

SRC_PRINT		= print/print.c

VAR_ENV_D		= srcs/environment_variables/

SRCS_BUILT_INSD	= srcs/builtins/

EXEC_D			= srcs/execution/

SRC_SIG			= srcs/signal.c srcs/signal2.c

SRC_VAR_ENV		= $(addprefix $(VAR_ENV_D), environment.c) \
					$(addprefix $(VAR_ENV_D), environment_utils.c) \
					$(addprefix $(VAR_ENV_D), shell_level.c)

SRC_BUILT_INS	= $(addprefix $(SRCS_BUILT_INSD), built_ins.c) \
					$(addprefix $(SRCS_BUILT_INSD), cd.c) \
					$(addprefix $(SRCS_BUILT_INSD), echo.c) \
					$(addprefix $(SRCS_BUILT_INSD), env.c) \
					$(addprefix $(SRCS_BUILT_INSD), export.c) \
					$(addprefix $(SRCS_BUILT_INSD), pwd.c) \
					$(addprefix $(SRCS_BUILT_INSD), unset.c) \
					$(addprefix $(SRCS_BUILT_INSD), exit.c) \
					$(addprefix $(SRCS_BUILT_INSD), variable_utils.c)

SRC_EXEC		= $(addprefix $(EXEC_D), execution.c) \
					$(addprefix $(EXEC_D), get_env_var.c) \
					$(addprefix $(EXEC_D), execution_utils.c) \
					$(addprefix $(EXEC_D), child_execution.c) \
					$(addprefix $(EXEC_D), here_doc.c) \
					$(addprefix $(EXEC_D), ft_free_exec.c) \
					$(addprefix $(EXEC_D), child_execution_utils.c)

OBJS			= $(SRC:.c=.o) $(SRC_ALLOC:.c=.o) ${SRC_LEXER:.c=.o} \
					$(SRC_PARSING:.c=.o) $(SRC_PRINT:.c=.o) $(SRC_VAR_ENV:.c=.o) \
					$(SRC_BUILT_INS:.c=.o) $(SRC_EXEC:.c=.o) $(SRC_SIG:.c=.o)

LIBFT			= ./libft/libft.a

all: libft $(NAME)
	
$(NAME): $(OBJS) Makefile
	${CC} $(CFLAGS) $(FFLAGS) -lreadline $(RL_INC) $(RL_LIB) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(FFLAGS) $(RL_INC) -c $< -o $@ -I ./includes

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
