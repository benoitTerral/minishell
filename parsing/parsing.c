/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:01:26 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/24 10:58:15 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing(char *line)
{
	char	**arg;

	if (!line || line[0] == '\0')
	{
		ft_free(&line);
		return (-1);
	}
	if (check_error_quote(line))
		return (-1);
	line = parsing_dollar(line);
	arg = split_quote(line);
	if (!arg)
	{
		ft_free(&line);
		return (-1);
	}
	printsplit(arg);
	ft_free_split(arg);
	ft_free(&line);
	return (0);
}
