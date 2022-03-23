/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:22:09 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/23 15:35:35 by laraujo          ###   ########lyon.fr   */
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
