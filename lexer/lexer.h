/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:03:52 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/04 17:16:22 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../includes/minishell.h"

/*---MSG_ERROR---*/

# define ERROR_OP "MiniShell: bad operator\n"

/*---TOKEN---*/

# define CMD		1
# define REDIN		2
# define HERE_DOC	3
# define REDOUT		4
# define D_REDOUT	5

/*---Struct---*/

typedef struct s_data
{
	int				token;
	char			**data;
	int				nbr_arg;
	struct s_data	*next;
}				t_data;

/*---lexer.c---*/

t_data	*lexer(char **arg);
int		strdup_token(int token, char **arg, int nbr_arg, t_data **newlist);

/*---lst.c---*/

void	ft_lstadd_back_data(t_data ***alst, t_data *new);
t_data	*ft_lstnew_data(int token, char **data, int nbr_arg);
t_data	*ft_lstlast_data(t_data **lst);
void	ft_lstclear_data(t_data **lst);

#endif