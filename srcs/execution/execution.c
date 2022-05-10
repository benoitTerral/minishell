/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:25:20 by bterral           #+#    #+#             */
/*   Updated: 2022/05/10 11:30:52 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup_endl(const char *s)
{
	char	*output;
	size_t	i;

	output = (char *)malloc(sizeof(*output) * (ft_strlen(s) + 2));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\n';
	output[i + 1] = '\0';
	return (output);
}

void	dup_buffer(char **buffer, char *line)
{
	char	*temp;

	temp = line;
	line = ft_strdup_endl(temp);
	free(temp);
	if (*buffer && buffer)
	{
		temp = ft_strdup(*buffer);
		free(*buffer);
		*buffer = ft_strjoin(temp, line);
		ft_free(&temp);
	}
	else
		*buffer = ft_strdup(line);
	free(line);
}

void	child_here_doc(char *delim, int fd[2], t_env **env)
{
	char	*line;
	char	*buffer;
	int		len;

	len = ft_strlen(delim);
	buffer = NULL;
	while (1)
	{
		line = parsing_dollar(readline("> "), env);
		if (!line)
		{
			if (buffer)
				write(fd[1], buffer, ft_strlen(buffer));
			break ;
		}
		else if (ft_strcmp(line, delim))
		{
			ft_free(&line);
			if (buffer)
				write(fd[1], buffer, ft_strlen(buffer));
			break ;
		}
		dup_buffer(&buffer, line);
	}
	exit(close(fd[1]));
}



int	get_here_doc(char *delim, t_env **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
		ft_dprintf(2, "here_doc error");
	pid = fork();
	if (pid == 0)
	{
		set_sig(&sig_handler_here);
		child_here_doc(delim, fd, env);
	}
	close(fd[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_ret_sig = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_ret_sig = WTERMSIG(status);
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
	else if (WIFSIGNALED(g_ret_sig))
		g_ret_sig = WTERMSIG(g_ret_sig);
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
