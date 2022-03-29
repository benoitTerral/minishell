/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:03:52 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/29 15:56:50 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../minishell.h"

/*---MSG_ERROR---*/

# define ERROR_OP "MiniShell: bad operator\n"

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

/*---lst.c---*/

t_data	*ft_lstnew(int token, char **data, int nbr_arg);
void	ft_lstclear(t_data **lst);

#endif