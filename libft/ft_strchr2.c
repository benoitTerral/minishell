/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:11:08 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/23 16:49:32 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../parsing/parsing.h"

// //  <-

// static int	jump_single_quote(char *str, int *i, int *quote)
// {
// 	*quote = status_quote(*quote, str[*i]);

	
// 	if (*quote == SQUOTE_STOP || *quote == DQUOTE_STOP) //condition arret
// 		return (0);
// 	if (*quote == SQUOTE_START || *quote == DQUOTE_START)
// 	{
// 		printf(GREEN"Q_START=%d\n", *i);
// 		*i += 1;
// 		while (*quote != SQUOTE_STOP && *quote != DQUOTE_STOP)
// 		{
// 			*quote = status_quote(*quote, str[*i]);
// 			if (*quote == QUOTE_ERROR)
// 			{
// 				dprintf(STDERR_FILENO, RED ERROR_QUOTE WHITE);
// 				return (QUOTE_ERROR);
// 			}
// 			*i += 1;
// 		}
// 		printf(YELLOW"Q_STOP=%d\n"WHITE, *i - 1);
// 		if (!str[*i])
// 			return (0);
// 		*quote = NO_QUOTE;
// 		if (QUOTE_ERROR == jump_quote(str, i, quote))
// 			return (QUOTE_ERROR);
// 	}
// 	return (0);
// }

char	*ft_strchr2(char *str, int search_char, int *i)
{
	*i = 0;
	while (str[*i])
	{
		if (str[*i] == (char) search_char)
			return ((char *)&str[*i]);
		*i += 1;
	}
	if (str[*i] == (char) search_char)
		return ((char *)&str[*i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	printf("%s\n", ft_strchr("salut slfh xsakb", ' '));
	printf("%s\n", strchr("salut slfh xsakb", ' '));
	printf("%s ", ft_strchr("slut", 97));
	printf("%s ", strchr("slut", 97));
	printf("%s ", ft_strchr("", 97));
	printf("%s ", strchr("", 97));
	printf("%s ", ft_strchr("salut", 0));
	printf("%s ", strchr("salut", 0));
}*/
