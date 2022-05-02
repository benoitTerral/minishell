/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:46:14 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/02 17:54:02 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_ret_sig;

int	prompt(t_env **head, char **env)
{
	t_data	*lex;
	char	*line;

	(void) env;
	line = readline(MINISHELL);
	if (!line)
	{
		free_env(head);
		printf("%se%sxi%st%s\n", BLUE, WHITE, RED, WHITE);
		exit(g_ret_sig);
	}
	else
	{
		add_history(line);
		lex = lexer(parsing(line, head), head);
		if (lex && is_build_in_bool(lex->str[0]) && lex->next == NULL)
			g_ret_sig = is_build_in(&lex);
		else if (lex)
			execute_command(&lex, head);
		ft_lstclear_data(&lex);
	}
	return (0);
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_ret_sig = 1;
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	init_termios(void)
{
	struct termios	old_term;
	struct termios	new_term;

	tcgetattr(ttyslot(), &old_term);
	new_term = old_term;
	new_term.c_lflag &= ~(ECHOCTL);
	tcsetattr(ttyslot(), TCSANOW, &new_term);
}

int	main(int argc, char **argv, char **env)
{
	t_env	*head;
	int		ret;

	(void) argv;
	if (argc != 1)
		return (-1);
	init_env_var(env, &head);
	init_termios();
	signal(SIGINT, &sig_handler);
	signal(SIGQUIT, &sig_handler);
	while (1)
	{
		ret = prompt(&head, env);
		if (ret)
			return (0);
	}
}
