/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:46:14 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/04 17:16:22 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_data	*lex;
	t_data	*start;

	(void) argv;
	(void) env;
	if (argc != 1)
		return (-1);
	while (1)
	{
		line = readline(MINISHELL);
		if (!line)
			return (0);
		add_history(line);
		if (!ft_strncmp(line, "exit", ft_strlen("exit")))
		{
			free(line);
			dprintf(STDOUT_FILENO, "%se%sxi%st%s\n", BLUE, WHITE, RED, WHITE);
			return (1);
		}
		else
		{
			lex = lexer(parsing(line));
			if (lex)
			{
				start = lex;
				printf("\nTOKEN=%d", lex->token);
				printsplit(lex->data);
				printf("lex->next=%p\n", lex->next);
				while (lex->next)
				{
					lex = lex->next;
					printf("\nTOKEN=%d", lex->token);
					printsplit(lex->data);
					printf("lex->next=%p\n", lex->next);
				}
				lex = start;
				ft_lstclear_data(&lex);
			}
		}
	}
}
