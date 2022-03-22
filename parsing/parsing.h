/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:43:20 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/22 15:35:22 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minishell.h"

/*---define---*/

# define WHITESPACE	" \n\t\f\v\f\r"
# define NO_QUOTE		0
# define QUOTE_ERROR	-10
# define SQUOTE_START	1
# define SQUOTE_STOP	-1
# define DQUOTE_START	2
# define DQUOTE_STOP	-2

/*---token---*/

# define CMD	1
# define PIPE	2
# define REDI	3

/*---MSG_ERROR---*/

# define ERROR_QUOTE "MiniShell: missing quote\n"

/*---Struct---*/

typedef struct s_data
{
	int		token;
	char	**data;
	int		nbr_arg;
}				t_data;

typedef struct s_index
{
	int	i;
	int	j;
	int	k;
}				t_index;

/*---dollar.c---*/

char	*get_var_env(char *pt);
char	*join_var_env(char *line, char *var, int dollar);
char	*parsing_dollar(char *line); //Modif My_getenv()

/*---parsing.c---*/

int		parsing(char *line);

/*---quote.c---*/

char	**split_quote(char *str);

#endif