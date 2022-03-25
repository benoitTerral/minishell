/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:03:36 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/25 16:37:29 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_data	*lexer(char **arg)
{
	int		i;
	t_data	*lexer;

	if (!arg)
		return (NULL);
	i = 0;
	printf("parsing = OK\n");
	while (arg[i] != NULL && *arg[i] != '|' && *arg[i] != '>' && *arg[i] != '<')
		i++;
	lexer = ft_lstnew(CMD, arg, i);
	
	//printsplit(lexer->data);
	ft_free_split(arg);
	return (lexer);
}
