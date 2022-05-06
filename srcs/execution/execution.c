/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:25:20 by bterral           #+#    #+#             */
/*   Updated: 2022/05/06 14:56:23 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_here_doc(char *delim, t_env **env)
{
	char	*line;
	int		len;
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
		ft_dprintf(2, "here_doc error");
	pid = fork();
	if (pid == 0)
	{
		set_sig(&sig_handler_here);
		line = NULL;
		len = ft_strlen(delim);
		while (1)
		{
			line = parsing_dollar(readline("> "), env);
			if (ft_strcmp(line, delim))
				break ;
			if (!line)
				break ;
			if (write(fd[1], line, ft_strlen(line)) == -1)
				ft_dprintf(2, "Error reading the here_doc");
			free(line);
		}
		free(line);
		close(fd[1]);
		exit(0);
	}
	close(fd[1]);
	waitpid(pid, &status, 0);
	return (fd[0]);
}

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
	if (WIFSIGNALED(g_ret_sig))
		g_ret_sig = WTERMSIG(g_ret_sig);
	return (g_ret_sig);
}

void	free_paths(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

void	free_all(char **envp, t_exec *exec)
{
	if (envp)
		free_paths(envp);
	if (exec)
		free(exec);
}

int	execute_command(t_data **start, t_env **env, t_termios *term)
{
	int		nbr_pipes;
	t_exec	*exec;
	char	**envp;

	nbr_pipes = nbr_of_cmd(start);
	exec = ft_calloc(nbr_pipes, sizeof(t_exec));
	if (!exec)
		exit(1);
	if (populate_exec_table(*start, exec, nbr_pipes, env))
		return (1);
	tcsetattr(0, TCSANOW, &term->old_term);
	set_sig(&sig_handler_m);
	envp = get_paths(&(*start)->head);
	get_abs_path_cmd(exec, nbr_pipes, envp);
	child_process(exec, nbr_pipes, envp, term);
	wait_all_pid(exec, nbr_pipes);
	free_all(envp, exec);
	return (0);
}
