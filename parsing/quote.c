/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:33:06 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/04 11:34:33 by bterral          ###   ########.fr       */
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
			*quote = status_quote(*quote, str[(*i)++]);
		if (!str[*i])
			return (0);
		*quote = NO_QUOTE;
		jump_quote(str, i, quote);
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
		jump_quote(str, &i, &quote);
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

static char	**enddup_tab(t_index ind, char **arg, char *str)
{
	arg[ind.j] = ft_substr(str, ind.i_save, ind.i - ind.i_save);
	arg[ind.j + 1] = NULL;
	ft_free(&str);
	return (arg);
}

static char	**strdup_tab(char *str, int nb_word)
{
	char	**arg;
	t_index	ind;

	init_index(&ind.i, &ind.j, &ind.i_save, &ind.quote);
	arg = malloc(sizeof(char *) * (nb_word + 1));
	if (!arg)
		return (NULL);
	while (str[ind.i])
	{
		//jump_delquote(&str, &ind.i, &ind.quote);
		jump_quote(str, &ind.i, &ind.quote);
		if (!str[ind.i])
			return (enddup_tab(ind, arg, str));
		if (is_whitespace(str[ind.i]) && ind.quote == NO_QUOTE)
		{
			arg[ind.j++] = ft_substr(str, ind.i_save, ind.i - ind.i_save);
			while (is_whitespace(str[ind.i]))
				ind.i_save = ++ind.i;
		}
		else
			ind.i++;
	}
	return (enddup_tab(ind, arg, str));
}

char	**split_quote(char *string)
{
	char	*str;
	int		nb_word;
	char	**arg;

	if (!string)
		return (NULL);
	ft_dprintf(1, "Split_line=%s\n", string);
	str = ft_strtrim(string, WHITESPACE);
	if (!str)
		return (NULL);
	nb_word = cpt_word(str);
	if (nb_word == QUOTE_ERROR)
		return (NULL);
	arg = strdup_tab(str, nb_word);
	if (arg)
		return (arg);
	return (NULL);
}
