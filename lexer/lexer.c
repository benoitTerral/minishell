/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:03:36 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/01 16:08:44 by laraujo          ###   ########lyon.fr   */
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

int	strchr_op(char **arg, int *i)
{
	while (arg[*i] != NULL && *arg[*i] != '|' && *arg[*i] != '>'
		&& *arg[*i] != '<')
		*i += 1;
	if (arg[*i] == NULL)
		return (0);
	if (arg[*i] != NULL && arg[*i][0] == '|')
		return (CMD);
	else if (arg[*i][0] == '<' && arg[*i][1] == '\0')
		return (REDIN);
	else if (arg[*i][0] == '<' && arg[*i][1] != '\0')
		return (HERE_DOC);
	else if (arg[*i][0] == '>' && arg[*i][1] == '\0')
		return (REDOUT);
	else if (arg[*i][0] == '>' && arg[*i][1] != '\0')
		return (D_REDOUT);
	return (0);
}

int	addnext_token(t_data **lexer, int i, char **arg)
{
	int	j;
	int	op;

	j = 0;
	while (j < i)
	{
		op = strchr_op(arg, &j);
		if (!op || op == CMD)
			break ;
		ft_lstadd_back(&lexer, ft_lstnew(op, &arg[j], i));
		j += 1;
	}
	return (0);
}

t_data	*lexer(char **arg)
{
	int		i;
	t_data	*lexer;
	t_data	*first;

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
	i = 0;
	while (arg[i] != NULL && *arg[i] != '|')
		i++;
	lexer = ft_lstnew(CMD, arg, i);
	first = lexer;
	addnext_token(&lexer, i, arg);
	ft_free_split(arg);
	return (first);
}
