/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:01:26 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/04 11:34:24 by bterral          ###   ########.fr       */
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
			ft_dprintf(STDERR_FILENO, RED ERROR_TOKEN"`%c'\n" WHITE, *arg[i]);
			return (1);
		}
		else if (is_operator(*arg[i]) && arg[i + 1] != NULL
			&& *arg[i + 1] == '|')
		{
			ft_dprintf(STDERR_FILENO, RED ERROR_TOKEN"`%c'\n" WHITE, *arg[i]);
			return (1);
		}
		else if ((*arg[i] == '<' || *arg[i] == '>') && arg[i + 1] != NULL
			&& is_operator(*arg[i + 1]))
		{
			ft_dprintf(STDERR_FILENO, RED ERROR_TOKEN"`%c'\n" WHITE, *arg[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**parsing(char *line, t_env **head)
{
	char	**arg;

	if (!line || line[0] == '\0')
		return (ft_free(&line));
	if (check_error_quote(line))
		return (NULL);
	line = parsing_operator(line);
	line = parsing_dollar(line, head);
	arg = split_quote(line);
	if (!arg)
		return (ft_free(&line));
	if (check_error_operator(arg))
	{
		ft_free_split(arg);
		return (ft_free(&line));
	}
	// printsplit(arg);
	ft_free(&line);
	return (arg);
}
