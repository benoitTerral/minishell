/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:25:20 by bterral           #+#    #+#             */
/*   Updated: 2022/05/17 10:58:54 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	wait_all_pid(t_exec *exec, int nbr_pipes)
{
	int	i;

	i = 0;
	while (i < nbr_pipes)
	{
		waitpid(exec[i].pid, &g_ret_sig, 0);
		if (exec[i].is_cmd)
			free(exec[i].cmd_full_path);
		i++;
	}
	if (WIFEXITED(g_ret_sig))
		g_ret_sig = WEXITSTATUS(g_ret_sig);
	else if (WIFSIGNALED(g_ret_sig))
	{
		if (g_ret_sig == 2)
			g_ret_sig = 130;
		else if (g_ret_sig == 3)
			g_ret_sig = 131;
		else
			g_ret_sig = WTERMSIG(g_ret_sig);
	}
	else
		g_ret_sig = 0;
	return (g_ret_sig);
}

int	execute_command(t_data **start, t_env **env, t_termios *term)
{
	int		nbr_pipes;
	t_exec	*exec;
	char	**envp;

	g_ret_sig = 0;
	envp = 0;
	nbr_pipes = nbr_of_cmd(start);
	exec = ft_calloc(nbr_pipes, sizeof(t_exec));
	if (!exec)
		exit(1);
	if (populate_exec_table(*start, exec, nbr_pipes, env))
		return (1);
	tcsetattr(0, TCSANOW, &term->old_term);
	set_sig(&sig_handler_m);
	if (!g_ret_sig)
	{
		envp = get_paths(&(*start)->head);
		get_abs_path_cmd(exec, nbr_pipes, envp);
		child_process(exec, nbr_pipes, term);
		wait_all_pid(exec, nbr_pipes);
	}
	free_all(envp, exec);
	return (0);
}
