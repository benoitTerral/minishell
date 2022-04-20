/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:46:14 by laraujo           #+#    #+#             */
/*   Updated: 2022/04/19 17:36:34 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_data	*lex;
	t_data	*start;
	t_env	*head;

	(void) argv;
	(void) env;
	if (argc != 1)
		return (-1);
	init_env_var(env, &head);
	while (1)
	{
		line = readline(MINISHELL);
		if (!line)
			return (0);
		add_history(line);
		if (!ft_strncmp(line, "exit", ft_strlen("exit")))
		{
			free(line);
			free_env(&head);
			dprintf(STDOUT_FILENO, "%se%sxi%st%s\n", BLUE, WHITE, RED, WHITE);
			return (1);
		}
		else
		{
			lex = lexer(parsing(line), &head);
			start = lex;
			execute_command(&start);
			while (lex)
			{
				is_build_in(lex);
				printf("\nTOKEN=%d", lex->token);
				printsplit(lex->str);
				printf("lex->next=%p\n", lex->next);
				lex = lex->next;
			}
			ft_lstclear_data(&lex);
		}
	}
}
