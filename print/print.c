/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:50:33 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/06 15:16:28 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	printsplit(char **split)
{
	int	j;

	j = 0;
	ft_dprintf(1, "\n");
	while (split[j])
	{
		ft_dprintf(1, "ARG[%d]=%s\n", j, split[j]);
		j++;
	}
	ft_dprintf(1, "ARG[%d]=%s\n", j, split[j]);
}

void	printdata(t_data *lexer)
{
	if (lexer)
	{
		ft_dprintf(1, "\nTOKEN=%d", lexer->token);
		printsplit(lexer->str);
		ft_dprintf(1, "lexer->next=%p\n", lexer->next);
		while (lexer->next)
		{
			lexer = lexer->next;
			ft_dprintf(1, "\nTOKEN=%d", lexer->token);
			printsplit(lexer->str);
			ft_dprintf(1, "lexer->next=%p\n", lexer->next);
		}
	}
}
