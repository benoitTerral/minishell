/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:25:58 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/12 13:06:22 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		g_ret_sig = 1;
		ft_dprintf(1, "> \n");
		exit(1);
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
}

void	sig_handler_child(int sig)
{
	if (sig == SIGINT)
	{
		g_ret_sig = 130;
		exit(130);
	}
	else if (sig == SIGQUIT)
	{
		g_ret_sig = 131;
		exit(131);
	}
}

void	sig_handler_m(int sig)
{
	if (sig == SIGINT)
	{
		dprintf(2, "\n");
		return ;
	}
	else if (sig == SIGQUIT)
	{
		dprintf(2, " Quit: 3\n");
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
