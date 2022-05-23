/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:54:36 by bterral           #+#    #+#             */
/*   Updated: 2022/05/23 17:47:03 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define ERROR_FORK "minishell: fork: Resource temporarily unavailable\n"

void	manage_fd_in(t_exec *exec, int i, t_p p_fd)
{
	if (exec[i].fd_in == -1)
		exit(1);
	else if (exec[i].fd_in)
		dup2(exec[i].fd_in, STDIN_FILENO);
	else
		dup2(*(p_fd.fd_tmp), STDIN_FILENO);
	if (exec[i].fd_in)
		close(exec[i].fd_in);
	if (*(p_fd.fd_tmp))
		close(*(p_fd.fd_tmp));
	if (p_fd.fd[0])
		close(p_fd.fd[0]);
}

void	manage_fd_out(t_exec *exec, int i, t_p p_fd)
{
	if (exec[i].fd_out == -1)
		exit(1);
	else if (exec[i].fd_out)
		dup2(exec[i].fd_out, STDOUT_FILENO);
	else if (i == (p_fd.nbr_cmd - 1))
		dup2(1, STDOUT_FILENO);
	else
		dup2(p_fd.fd[1], STDOUT_FILENO);
	close(p_fd.fd[1]);
	if (exec[i].fd_out)
		close(exec[i].fd_out);
}

void	execute_child_process(t_exec *exec, int i, t_p p_fd, t_termios *term)
{
	char	**env;

	set_sig(&sig_handler_child);
	manage_fd_in(exec, i, p_fd);
	manage_fd_out(exec, i, p_fd);
	if (exec[i].is_cmd && exec[i].is_builtin)
		exit(is_build_in(&(exec[i].data), p_fd.nbr_cmd, term));
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
	int	i;
	t_p	p_fd;

	i = 0;
	p_fd.fd_tmp = (int *)malloc(sizeof(int) * 1);
	*(p_fd.fd_tmp) = 10;
	p_fd.nbr_cmd = nbr_pipes;
	while (i < nbr_pipes)
	{
		if (pipe(p_fd.fd) == -1)
			return (ft_dprintf(STDERR_FILENO, RED "pipe failed" WHITE));
		exec[i].pid = fork();
		if (exec[i].pid == -1)
		{
			ft_dprintf(2, RED ERROR_FORK WHITE);
			close(p_fd.fd[0]);
			close(p_fd.fd[1]);
			exit(1);
		}
		if (exec[i].pid == 0)
			execute_child_process(exec, i, p_fd, term);
		if (exec[i].fd_in && exec[i].fd_in != -1)
			close(exec[i].fd_in);
		if (exec[i].fd_out && exec[i].fd_out != -1)
			close(exec[i].fd_out);
		close(p_fd.fd[1]);
		close(*(p_fd.fd_tmp));
		*(p_fd.fd_tmp) = p_fd.fd[0];
		i++;
	}
	if (*(p_fd.fd_tmp))
		close(*(p_fd.fd_tmp));
	free(p_fd.fd_tmp);
	return (0);
}
