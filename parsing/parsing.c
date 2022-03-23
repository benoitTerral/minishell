/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:01:26 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/23 14:28:59 by laraujo          ###   ########lyon.fr   */
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

void	printsplit(char **split)
{
	int	j;
	j = 0;
	printf("\n");
	while (split[j])
	{
		printf("ARG[%d]=%s\n", j, split[j]);
		j++;
	}
	printf("ARG[%d]=%s\n", j, split[j]);
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
	if (!arg)
	{
		ft_free(line);
		return (-1);
	}
	printsplit(arg);
	ft_free(line);
	return (0);
}
