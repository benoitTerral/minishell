/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:46:14 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/29 16:18:26 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_data	*lex;

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
				printsplit(lex->data);
				ft_lstclear(&lex);
			}
		}
	}
}
