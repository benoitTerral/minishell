/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:01:26 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/01 15:16:59 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_error_operator(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (is_operator(*arg[i]) && arg[i + 1] == NULL)
		{
			dprintf(STDERR_FILENO, RED ERROR_TOKEN"`%c'\n" WHITE, *arg[i]);
			return (1);
		}
		else if (is_operator(*arg[i]) && arg[i + 1] != NULL
			&& is_operator(*arg[i + 1]))
		{
			dprintf(STDERR_FILENO, RED ERROR_TOKEN WHITE);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**parsing(char *line)
{
	char	**arg;

	if (!line || line[0] == '\0')
	{
		ft_free(&line);
		return (NULL);
	}
	if (check_error_quote(line))
		return (NULL);
	line = parsing_operator(line);
	line = parsing_dollar(line);
	arg = split_quote(line);
	if (!arg)
	{
		ft_free(&line);
		return (NULL);
	}
	if (check_error_operator(arg))
	{
		ft_free(&line);
		return (NULL);
	}
	printsplit(arg);
	ft_free(&line);
	return (arg);
}
