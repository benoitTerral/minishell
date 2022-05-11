/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:54:36 by bterral           #+#    #+#             */
/*   Updated: 2022/05/11 15:53:04 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define ERROR_FORK "minishell: fork: Resource temporarily unavailable\n"

void	child_here_doc(char *delim, int fd[2], t_env **env)
{
	char	*line;
	char	*buffer;
	int		len;

	len = ft_strlen(delim);
	buffer = NULL;
	while (1)
	{
		line = parsing_dollar(readline("> "), env, 0, NO_QUOTE);
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

void	manage_fd_in(t_exec *exec, int i)
{
	if (exec[i].fd_in == -1)
		exit(1);
	else if (exec[i].fd_in)
		dup2(exec[i].fd_in, STDIN_FILENO);
	else if (i != 0)
		dup2(exec[i - 1].fd[0], STDIN_FILENO);
	close(exec[i].fd[0]);
}

void	manage_fd_out(t_exec *exec, int nbr_cmd, int i)
{
	if (exec[i].fd_out == -1)
		exit(1);
	else if (exec[i].fd_out)
		dup2(exec[i].fd_out, STDOUT_FILENO);
	else if (i == (nbr_cmd - 1))
		dup2(1, STDOUT_FILENO);
	else
		dup2(exec[i].fd[1], STDOUT_FILENO);
}

void	execute_child_process(t_exec *exec, int nbr_p, int i, t_termios *term)
{
	char	**env;

	set_sig(&sig_handler_child);
	manage_fd_in(exec, i);
	manage_fd_out(exec, nbr_p, i);
	if (exec[i].is_cmd && exec[i].is_builtin)
		exit(is_build_in(&(exec[i].data), nbr_p, term));
	else if (exec[i].is_cmd)
	{
		env = env_lst_to_char(exec[i].data->head);
		if (execve(exec[i].cmd_full_path, exec[i].cmd[0], env) == -1)
			exit(127);
	}
	else
		exit (0);
}

int	child_process(t_exec *exec, int nbr_pipes, t_termios *term)
{
	int		i;

	i = 0;
	while (i < nbr_pipes)
	{
		exec[i].pid = fork();
		if (exec[i].pid == -1)
		{
			ft_dprintf(2, RED ERROR_FORK WHITE);
			exit(1);
		}
		if (exec[i].pid == 0)
			execute_child_process(exec, nbr_pipes, i, term);
		close(exec[i].fd[1]);
		if (i != 0)
			close(exec[i - 1].fd[0]);
		else if (i == 0 && nbr_pipes == 1)
			close(exec[i].fd[0]);
		i++;
	}
	return (0);
}
