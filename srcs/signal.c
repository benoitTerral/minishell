/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:25:58 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/24 11:22:59 by bterral          ###   ########.fr       */
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
		ft_dprintf(2, "\n");
		return ;
	}
	else if (sig == SIGQUIT)
	{
		ft_dprintf(2, " Quit: 3\n");
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
