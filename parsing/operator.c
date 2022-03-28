/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:02:34 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/28 18:08:54 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_operator(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	else
		return (0);
}

char	*parsing_operator(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|' || line[i] == '<' || line[i] == '>')
		{
			if (!is_whitespace(line[i - 1]) && (line[i - 1] != line[i]))
				stradd_index(&line, i, ' ');
			i++;
			printf("=%c\n", line[i]);
			if (line[i + 1] == '\0')
				break ;
			if (!is_whitespace(line[i + 1]) && (line[i + 1] != line[i]))
			{
				stradd_index(&line, i + 1, ' ');
			}
		}
		i++;
	}
	return (line);
}
