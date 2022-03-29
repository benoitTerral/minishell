/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:03:36 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/29 16:11:56 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	check_operator(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] != NULL)
	{
		if (arg[i][0] == '|' && arg[i][1] != '\0' && arg[i][1] == '|')
			return (1);
		if (arg[i][0] == '<' && arg[i][1] != '\0' && arg[i][1] == '<'
			&& arg[i][2] != '\0' && arg[i][2] == '<')
			return (1);
		if (arg[i][0] == '>' && arg[i][1] != '\0' && arg[i][1] == '>'
			&& arg[i][2] != '\0' && arg[i][2] == '>')
			return (1);
		i++;
	}
	return (0);
}

t_data	*lexer(char **arg)
{
	int		i;
	t_data	*lexer;

	if (!arg)
		return (NULL);
	i = 0;
	if (check_operator(arg))
	{
		dprintf(STDERR_FILENO, RED ERROR_OP WHITE);
		ft_free_split(arg);
		return (0);
	}
	printf("parsing = OK\n");
	while (arg[i] != NULL && *arg[i] != '|' && *arg[i] != '>' && *arg[i] != '<')
		i++;
	lexer = ft_lstnew(CMD, arg, i);
	
	//printsplit(lexer->data);
	ft_free_split(arg);
	return (lexer);
}
