/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:01:26 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/22 14:55:09 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	del_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_whitespace(str[i]))
		i++;
	}
}

int	parsing(char *line)
{
	char	**arg;

	if (!line || line[0] == '\n')
	{
		ft_free(line);
		return (-1);
	}
	line = parsing_dollar(line);
	printf("END_line =%s", line);
	arg = split_quote(line);
	ft_free(line);
	return (0);
}
