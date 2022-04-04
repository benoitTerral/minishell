/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:02:34 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/04 14:58:43 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	jump_quote(char *str, int *i, int *quote)
{
	if (!str[*i])
		return (-1);
	*quote = status_quote(*quote, str[*i]);
	if (*quote == SQUOTE_STOP || *quote == DQUOTE_STOP)
		return (0);
	if (*quote == SQUOTE_START || *quote == DQUOTE_START)
	{
		*i += 1;
		while (*quote != SQUOTE_STOP && *quote != DQUOTE_STOP)
		{
			*quote = status_quote(*quote, str[*i]);
			*i += 1;
		}
		if (!str[*i])
			return (-1);
		*quote = NO_QUOTE;
		jump_quote(str, i, quote);
	}
	return (0);
}

int	is_operator(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	else
		return (0);
}

int	is_redi(char c)
{
	if (c == '<' || c == '>')
		return (1);
	else
		return (0);
}

char	*parsing_operator(char *line)
{
	int	i;
	int	quote;

	i = 0;
	quote = NO_QUOTE;
	while (line[i])
	{
		if (jump_quote(line, &i, &quote) || !line[i])
			return (line);
		if (line[i] == '|' || line[i] == '<' || line[i] == '>')
		{
			if (i > 0 && !is_whitespace(line[i - 1]) && line[i - 1] != line[i])
				stradd_index(&line, i, ' ');
			i++;
			if (line[i] == '\0' || line[i + 1] == '\0')
				break ;
			if (!is_whitespace(line[i]) && (line[i] != line[i - 1]))
			{
				stradd_index(&line, i, ' ');
			}
		}
		else
			i++;
	}
	return (line);
}
