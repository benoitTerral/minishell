/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:25:58 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/05 12:11:04 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_sig(void (*sig_fonction)(int))
{
	signal(SIGINT, sig_fonction);
	signal(SIGQUIT, sig_fonction);
}

void	sig_handler_prompt(int sig)
{
	if (sig == SIGINT)
	{
		ft_dprintf(1, "\n");
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

void	sig_handler_here(int sig)
{
	if (sig == SIGINT)
	{
		exit(1);
		g_ret_sig = 1;
	}
	else if (sig == SIGQUIT)
	{
		return ;
	}
}

void	sig_handler_child(int sig)
{
	if (sig == SIGINT)
	{
		exit(1);
	}
	else if (sig == SIGQUIT)
	{
		exit(1);
	}
}

void	sig_handler_m(int sig)
{
	if (sig == SIGINT)
	{
		dprintf(2, "^C\n");
		return ;
	}
	else if (sig == SIGQUIT)
	{
		dprintf(2, "^\\Quit: 3\n");
		return ;
	}
}

void	sig_handler_disable(int sig)
{
	if (sig == SIGINT)
	{
		return ;
	}
	else if (sig == SIGQUIT)
	{
		return ;
	}
}
