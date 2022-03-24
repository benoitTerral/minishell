/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:28:55 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/24 15:21:11 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	strdel_index(char **str, int index)
{
	char	*temp;
	char	*end;

	end = ft_substr(*str, index + 1, ft_strlen(*str) - index);
	str[0][index] = '\0';
	temp = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin(temp, end);
	free(temp);
	free(end);
}

static int	jump_single_quote(char *str, int *i, int *quote, int search_char)
{
	*quote = status_quote(*quote, str[*i]);
	if (*quote == SQUOTE_STOP || *quote == DQUOTE_STOP)
		return (0);
	if (*quote == SQUOTE_START || *quote == DQUOTE_START)
	{
		*i += 1;
		while (*quote != SQUOTE_STOP && *quote != DQUOTE_STOP)
		{
			if (str[*i] == (char) search_char && *quote != SQUOTE_START)
				return (0);
			*quote = status_quote(*quote, str[*i]);
			*i += 1;
		}
		if (!str[*i])
			return (0);
		*quote = NO_QUOTE;
		jump_single_quote(str, i, quote, search_char);
	}
	return (0);
}

char	*ft_strchr2(char *str, int search_char, int *i, int *quote)
{
	*i = 0;
	while (str[*i])
	{
		jump_single_quote(str, i, quote, search_char);
		if (str[*i] == '\0')
			return (0);
		if (str[*i] == (char) search_char)
			return ((char *)&str[*i]);
		*i += 1;
	}
	if (str[*i] == (char) search_char)
		return ((char *)&str[*i]);
	return (0);
}
