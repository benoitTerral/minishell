/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:46:14 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/24 17:31:37 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;

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
			if (!parsing(line))
				printf("parsing = OK\n");
		}
	}
}
