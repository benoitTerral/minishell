/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:03:36 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/31 20:02:30 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	counter_arg(char **arg, int nbr_arg)
{
	int	i;
	int	save_nbr_arg;

	i = 0;
	save_nbr_arg = nbr_arg;
	while (i < save_nbr_arg)
	{
		if (is_redi(*arg[i]))
		{
			nbr_arg -= 2;
			i++;
		}
		i++;
	}
	return (nbr_arg);
}

int	strdup_token(int token, char **arg, int nbr_arg, t_data **newlist)
{
	int	i;
	int	j;

	if (token == REDIN || token == REDOUT || token == D_REDOUT || token == HERE_DOC)
	{
		i = -1;
		(*newlist)->data = malloc(sizeof(char *) * 3);
		if (!(*newlist)->data)
			return (-1);
		while (++i < 2)
		{
			jump_delquote(*(&arg), 0, NO_QUOTE);
			(*newlist)->data[i] = ft_strdup(*arg++);
		}
		(*newlist)->data[i] = NULL;
		(*newlist)->nbr_arg = 2;
	}
	if (token == CMD)
	{
		i = 0;
		j = 0;
		printf("count=%d\n", counter_arg(arg, nbr_arg));
		(*newlist)->data = malloc(sizeof(char *) * (counter_arg(arg, nbr_arg) + 1));
		if (!(*newlist)->data)
			return (-1);
		while (j < nbr_arg)
		{
			printf("c=%c\n", arg[j][0]);
			while (is_redi(arg[j][0]))
				j += 2;
			printf("c=%s\n", arg[j]);
			jump_delquote(&arg[j], 0, NO_QUOTE);
			(*newlist)->data[i++] = ft_strdup(arg[j++]);
		}
		(*newlist)->data[i] = NULL;
		(*newlist)->nbr_arg = nbr_arg;
	}
	return (0);
}

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
	printf("op=%c\n", *arg[*i]);
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

t_data	*lexer(char **arg)
{
	int		i;
	int		j;
	int		save_i;
	int		op;
	t_data	*lexer;
	t_data	*first;

	if (!arg)
		return (NULL);
	i = 0;
	save_i = 0;
	if (check_operator(arg))
	{
		dprintf(STDERR_FILENO, RED ERROR_OP WHITE);
		ft_free_split(arg);
		return (0);
	}
	printf("parsing = OK\n");
//	op = strchr_op(arg, &i);
	op = CMD;
	i = 0;
	while (arg[i] != NULL && *arg[i] != '|')
		i++;
	lexer = ft_lstnew(op, arg, i);
	first = lexer;
	j = 0;
	while (j < i)
	{
		op = strchr_op(&arg[j], &j);
		if (op == CMD)
			break ;
		printf("j=%d, i=%d, op=%d\n", j, i, op);
		ft_lstadd_back(&lexer, ft_lstnew(op, &arg[j], i));
		j += 1;
	}
//	FT_lstaddbask(&lexer, ft_lstnew(CMD, arg, i - save_i));

	//printsplit(lexer->data);
	ft_free_split(arg);
	return (first);
}
