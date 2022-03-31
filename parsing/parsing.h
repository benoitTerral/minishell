/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:43:20 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/31 15:42:07 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../includes/minishell.h"

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
	int	i_save;
	int	quote;
}				t_index;

/*---dollar.c---*/

char	*get_var_env(char *pt);
char	*join_var_env(char *line, char *var, int dollar);
char	*parsing_dollar(char *line); //Modif My_getenv()

/*---parsing.c---*/

int		parsing(char *line);

/*---parsing_utils.c---*/

void	strdel_index(char **str, int index);
char	*ft_strchr2(char *str, int search_char, int *i, int *quote);

/*---quote.c---*/

char	**split_quote(char *str);

/*---quote2.c---*/

int		status_quote(int quote, char c);
int		check_error_quote(char *str);
void	init_index(int *i, int *j, int *i_save, int *quote);
int		jump_delquote(char **str, int *i, int *quote);

#endif