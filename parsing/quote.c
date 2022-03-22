/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:33:06 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/22 19:31:01 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

int	jump_quote(char *str, int *i, int *quote)
{
	*quote = status_quote(*quote, str[*i]);
	if (*quote == SQUOTE_STOP || *quote == DQUOTE_STOP)
		return (0);
	if (*quote == SQUOTE_START || *quote == DQUOTE_START)
	{
		printf("Q_START=%d\n", *i);
		*i += 1;
		while (*quote != SQUOTE_STOP && *quote != DQUOTE_STOP)
		{
			*quote = status_quote(*quote, str[*i]);
			*i += 1;
			if (*quote == QUOTE_ERROR)
			{
				printf("ERROR\n");
				return (QUOTE_ERROR);
			}
		}
		printf("Q_STOP=%d\n", *i - 1);
		if (!str[*i])
			return (0);
		*quote = NO_QUOTE;
		if (QUOTE_ERROR == jump_quote(str, i, quote))
			return (QUOTE_ERROR);
	}
	return (0);
}

static int	cpt_word(char *str)
{
	int	quote;
	int	i;
	int	cpt;

	quote = NO_QUOTE;
	i = 0;
	cpt = 1;
	while (str[i])
	{
		if (QUOTE_ERROR == jump_quote(str, &i, &quote))
			return (QUOTE_ERROR);
		if (!str[i])
			return (cpt);
		if (is_whitespace(str[i]) && quote == NO_QUOTE)
		{
			cpt++;
			while (is_whitespace(str[i]))
				i++;
		}
		else
			i++;
	}
	return (cpt);
}

char	**split_quote(char *string)
{
	t_index	ind;
	char	*str;

	ind.i = 0;
	ind.j = 0;
	if (!string)
		return (NULL);
	str = ft_strtrim(string, WHITESPACE);
	if (!str)
		return (NULL);
	printf("trim=%s|\n", str);
	printf("cpt_word=%d\n", cpt_word(str));
	return (NULL);
}

/*
Fonction qui suprime l'element de la list
void strdel_index(char *str, int index);
*/