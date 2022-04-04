/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listdup_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:57:13 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/04 16:34:29 by laraujo          ###   ########lyon.fr   */
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
			if (arg[i + 1] == NULL || *arg[i + 1] == '|')
				return (nbr_arg - 1);
			else
				nbr_arg -= 2;
			i++;
		}
		i++;
	}
	return (nbr_arg);
}

int	dup_red(char **arg, t_data ***newlist)
{
	int	i;

	i = -1;
	(**newlist)->data = malloc(sizeof(char *) * 3);
	if (!(**newlist)->data)
		return (-1);
	while (++i < 2)
	{
		jump_delquote(&(*arg), 0, NO_QUOTE);
		(**newlist)->data[i] = ft_strdup(*arg++);
	}
	(**newlist)->data[i] = NULL;
	(**newlist)->nbr_arg = 2;
	return (0);
}

int	dup_cmd(char **arg, t_data ***newlist, int nbr_arg)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = counter_arg(arg, nbr_arg);
	(**newlist)->data = malloc(sizeof(char *) * (count + 1));
	if (!(**newlist)->data)
		return (-1);
	while (j < nbr_arg && count)
	{
		while (j < nbr_arg && is_redi(arg[j][0]))
			j += 2;
		if (j >= nbr_arg)
			break ;
		jump_delquote(&arg[j], 0, NO_QUOTE);
		(**newlist)->data[i++] = ft_strdup(arg[j++]);
	}
	(**newlist)->data[i] = NULL;
	(**newlist)->nbr_arg = nbr_arg;
	return (0);
}

int	strdup_token(int token, char **arg, int nbr_arg, t_data **newlist)
{
	if (token == REDIN || token == REDOUT || token == D_REDOUT
		|| token == HERE_DOC)
	{
		if (dup_red(arg, &newlist))
			return (-1);
		return (0);
	}
	else if (token == CMD)
	{
		if (dup_cmd(arg, &newlist, nbr_arg))
			return (-1);
		return (0);
	}
	return (0);
}
