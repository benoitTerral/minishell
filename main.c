/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:46:14 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/22 11:43:39 by laraujo          ###   ########lyon.fr   */
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

int	main(void)
{
	char	*line;

	while (1)
	{
		print_prompter();
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return (0);
		if (!ft_strncmp(line, "exit", ft_strlen("exit")))
		{
			free(line);
			dprintf(STDOUT_FILENO, "e%sx%si%st\n", RED, GREEN, YELLOW);
			return (1);
		}
		else
		{
			parsing(line);
		}
	}
}
