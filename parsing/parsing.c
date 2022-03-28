/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:01:26 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/28 13:06:09 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	printsplit(arg);
	ft_free(&line);
	return (arg);
}
