/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:01:26 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/23 19:01:50 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing(char *line)
{
	char	**arg;

	if (!line || line[0] == '\n')
	{
		ft_free(&line);
		return (-1);
	}
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
