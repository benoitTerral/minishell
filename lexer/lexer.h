/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:03:52 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/31 19:25:52 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../minishell.h"

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

void	ft_lstadd_back(t_data **alst, t_data *new);
t_data	*ft_lstnew(int token, char **data, int nbr_arg);
t_data	*ft_lstlast(t_data *lst);
void	ft_lstclear(t_data **lst);

#endif