/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:43:20 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/11 15:50:58 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../includes/minishell.h"

typedef struct s_env	t_env;

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

# define ERROR_QUOTE	"MiniShell: missing quote\n"
# define ERROR_TOKEN	"MiniShell: syntax error near unexpected token "

/*---Struct---*/

typedef struct s_index
{
	int	i;
	int	j;
	int	i_save;
	int	quote;
}				t_index;

/*---operator---*/

char	*parsing_operator(char *line);
int		is_operator(char c);
int		is_redi(char c);

/*---dollar.c---*/

char	*get_var_env(char *pt);
char	*join_var_env(char *line, char *var, int dollar, t_env **head);
char	*parsing_dollar(char *line, t_env **head, int *i, int *quote);

/*---parsing.c---*/

char	**parsing(char *line, t_env **head);

/*---parsing_utils.c---*/

int		is_whitespace(char c);
void	strdel_index(char **str, int index);
void	stradd_index(char **str, int index, char c);
char	*ft_strchr2(char *str, int search_char, int **i, int **quote);

/*---quote.c---*/

char	**split_quote(char *str);

/*---quote2.c---*/

int		status_quote(int quote, char c);
int		check_error_quote(char *str);
void	init_index(int *i, int *j, int *i_save, int *quote);
int		jump_delquote(char **str, int i, int quote);

#endif