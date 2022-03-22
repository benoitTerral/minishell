/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:43:20 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/22 13:30:59 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minishell.h"

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

/*---dollar.c---*/

char	*get_var_env(char *pt);
char	*join_var_env(char *line, char *var, int dollar);
char	*parsing_dollar(char *line); //Modif My_getenv()

/*---parsing.c---*/

int		parsing(char *line);

/*---quote.c---*/

char	**split_quote(char *str);

#endif