/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:22:09 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/01 15:16:40 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	jump_quote(char *str, int *i, int *quote)
{
	*quote = status_quote(*quote, str[*i]);
	if (*quote == SQUOTE_STOP || *quote == DQUOTE_STOP)
		return (0);
	if (*quote == SQUOTE_START || *quote == DQUOTE_START)
	{
		*i += 1;
		while (*quote != SQUOTE_STOP && *quote != DQUOTE_STOP)
		{
			*quote = status_quote(*quote, str[*i]);
			if (*quote == QUOTE_ERROR)
			{
				dprintf(STDERR_FILENO, RED ERROR_QUOTE WHITE);
				ft_free(&str);
				return (QUOTE_ERROR);
			}
			*i += 1;
		}
		if (!str[*i])
			return (0);
		*quote = NO_QUOTE;
		if (QUOTE_ERROR == jump_quote(str, i, quote))
			return (QUOTE_ERROR);
	}
	return (0);
}

int	check_error_quote(char *str)
{
	int	quote;
	int	i;

	quote = NO_QUOTE;
	i = 0;
	while (str[i])
	{
		if (QUOTE_ERROR == jump_quote(str, &i, &quote))
			return (QUOTE_ERROR);
		if (!str[i])
			return (0);
		if (is_whitespace(str[i]) && quote == NO_QUOTE)
		{
			while (is_whitespace(str[i]))
				i++;
		}
		else
			i++;
	}
	return (0);
}

int	status_quote(int quote, char c)
{
	if (c == '\0')
		return (QUOTE_ERROR);
	else if (c == '\'' && quote == NO_QUOTE)
		return (SQUOTE_START);
	else if (c == '"' && quote == NO_QUOTE)
		return (DQUOTE_START);
	else if (c == '\'' && quote == SQUOTE_START)
		return (SQUOTE_STOP);
	else if (c == '"' && quote == DQUOTE_START)
		return (DQUOTE_STOP);
	else
		return (quote);
}

void	init_index(int *i, int *j, int *i_save, int *quote)
{
	*i = 0;
	*j = 0;
	*i_save = 0;
	*quote = NO_QUOTE;
}

int	jump_delquote(char **str, int i, int quote)
{
	quote = status_quote(quote, str[0][i]);
	if (quote == SQUOTE_STOP || quote == DQUOTE_STOP)
		return (0);
	if (quote == SQUOTE_START || quote == DQUOTE_START)
	{
	//	printf(GREEN"Q_START=%d\n", i);
		strdel_index(str, i);
		while (quote != SQUOTE_STOP && quote != DQUOTE_STOP)
			quote = status_quote(quote, str[0][i++]);
		i--;
	//	printf(YELLOW"Q_STOP=%d\n"WHITE, i);
		strdel_index(str, i);
		if (!str[0][i])
			return (0);
		quote = NO_QUOTE;
		jump_delquote(str, i, quote);
	}
	else if (quote == 0 && str[0][i])
		jump_delquote(str, i + 1, quote);
	return (0);
}
