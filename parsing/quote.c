/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:33:06 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/23 14:30:45 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	strdel_index(char **str, int index);

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
	if (*quote == SQUOTE_STOP || *quote == DQUOTE_STOP) //condition arret
		return (0);
	if (*quote == SQUOTE_START || *quote == DQUOTE_START)
	{
//		printf(GREEN"Q_START=%d\n", *i);
		*i += 1;
		while (*quote != SQUOTE_STOP && *quote != DQUOTE_STOP)
		{
			*quote = status_quote(*quote, str[*i]);
			if (*quote == QUOTE_ERROR)
			{
				dprintf(STDERR_FILENO, RED ERROR_QUOTE WHITE);
				return (QUOTE_ERROR);
			}
			*i += 1;
		}
//		printf(YELLOW"Q_STOP=%d\n"WHITE, *i - 1);
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

int	jump_delquote(char **str, int *i, int *quote)
{
	*quote = status_quote(*quote, str[0][*i]);
	if (*quote == SQUOTE_STOP || *quote == DQUOTE_STOP) //condition arret
		return (0);
	if (*quote == SQUOTE_START || *quote == DQUOTE_START)
	{
//		printf(GREEN"Q_START=%d\n", *i);
		strdel_index(str, *i);
		//*i += 1;
		while (*quote != SQUOTE_STOP && *quote != DQUOTE_STOP)
		{
			*quote = status_quote(*quote, str[0][*i]);
			if (*quote == QUOTE_ERROR)
			{
				dprintf(STDERR_FILENO, RED ERROR_QUOTE WHITE);
				return (QUOTE_ERROR);
			}
			*i += 1;
		}
		*i -= 1;
//		printf(YELLOW"Q_STOP=%d\n"WHITE, *i);
		strdel_index(str, *i);
		if (!str[0][*i])
			return (0);
		*quote = NO_QUOTE;
		if (QUOTE_ERROR == jump_delquote(str, i, quote))
			return (QUOTE_ERROR);
	}
	return (0);
}

static char	**strdup_tab(char *str, int nb_word)
{
	int		quote;
	int		i;
	int		cpt;
	int		i_save;
	char	**arg;

	quote = NO_QUOTE;
	i = 0;
	i_save = 0;
	cpt = 0;
	arg = malloc(sizeof(char *) * (nb_word + 1));
	if (!arg)
		return (NULL);
	while (str[i])
	{
		jump_delquote(&str, &i, &quote);
		if (!str[i])
		{
			arg[cpt] = ft_substr(str, i_save, i - i_save);
//			printf("arg=%s\n", arg[cpt]);
			arg[cpt + 1] = NULL;
//			printf("arg=%s\n", arg[cpt + 1]);
			return (arg);
		}
		if (is_whitespace(str[i]) && quote == NO_QUOTE)
		{
			arg[cpt] = ft_substr(str, i_save, i - i_save);
//			printf("arg=%s\n", arg[cpt]);
			cpt++;
			while (is_whitespace(str[i]))
				i++;
			i_save = i;
		}
		else
			i++;
	}
	return (NULL);
}

char	**split_quote(char *string)
{
	char	*str;
	int		nb_word;
	char	**arg;

	if (!string)
		return (NULL);
	str = ft_strtrim(string, WHITESPACE);
	if (!str)
		return (NULL);
//	printf("trim=%s|\n", str);
	nb_word = cpt_word(str);
//	printf("cpt_word=%d\n", nb_word);
	if (nb_word == QUOTE_ERROR)
		return (NULL);
	arg = strdup_tab(str, nb_word);
	if (arg)
		return (arg);
	return (NULL);
}

/*
Fonction qui suprime l'element de la list
void strdel_index(char *str, int index);
*/