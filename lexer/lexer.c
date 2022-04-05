/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:03:36 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/05 15:14:46 by bterral          ###   ########.fr       */
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

int	addnext_token(t_data **lexer, char **arg, t_env **head)
{
	int	i;
	int	j;
	int	op;

	j = 0;
	i = 0;
	while (arg[j] != NULL)
	{
		j = i;
		while (arg[i] != NULL && *arg[i] != '|')
			i++;
		if (j)
			ft_lstadd_back_data(&lexer, ft_lstnew_data(CMD, &arg[j], i - j, head));
		while (j < i)
		{
			op = strchr_op(arg, &j);
			if (!op || op == CMD)
				break ;
			ft_lstadd_back_data(&lexer, ft_lstnew_data(op, &arg[j], i, head));
			j += 1;
		}
		i++;
	}
	return (0);
}

t_data	*lexer(char **arg, t_env **head)
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
	lexer = ft_lstnew_data(CMD, arg, i, head);
	first = lexer;
	addnext_token(&lexer, arg, head);
	ft_free_split(arg);
	return (first);
}
