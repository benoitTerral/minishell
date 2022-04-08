/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:50:33 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/08 12:37:17 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_prompter(void)
{
	dprintf(STDOUT_FILENO, "%sMin%siS", BLUE, WHITE);
	dprintf(STDOUT_FILENO, "h%sell%s $ ", RED, WHITE);
}

void	printsplit(char **split)
{
	int	j;

	j = 0;
	printf("\n");
	while (split[j])
	{
		printf("ARG[%d]=%s\n", j, split[j]);
		j++;
	}
	printf("ARG[%d]=%s\n", j, split[j]);
}

void	printdata(t_data *lexer)
{
	if (lexer)
	{
		is_build_in(lexer);
		printf("\nTOKEN=%d", lexer->token);
		printsplit(lexer->str);
		printf("lexer->next=%p\n", lexer->next);
		while (lexer->next)
		{
			lexer = lexer->next;
			is_build_in(lexer);
			printf("\nTOKEN=%d", lexer->token);
			printsplit(lexer->str);
			printf("lexer->next=%p\n", lexer->next);
		}
	}
}
