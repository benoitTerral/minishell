/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:25:20 by bterral           #+#    #+#             */
/*   Updated: 2022/04/27 17:59:56 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	child_process(t_exec *exec, int nbr_cmd, char **envp)
{
	int i;

	i = 0;
	while (i < nbr_cmd)
	{
		exec[i].pid = fork();
		if (exec[i].pid == 0)
		{
			if (exec[i].fd_in)
				dup2(exec[i].fd_in, STDIN_FILENO);
			else if (i != 0)
				dup2(exec[i - 1].fd[0], STDIN_FILENO);
			close(exec[i].fd[0]);
			if (exec[i].fd_out)
				dup2(exec[i].fd_out, STDOUT_FILENO);
			else if (i == (nbr_cmd - 1)) 
				dup2(1, STDOUT_FILENO);
			else
				dup2(exec[i].fd[1], STDOUT_FILENO);
			execve(exec[i].cmd_full_path, exec[i].cmd[0], envp);
		}
		close(exec[i].fd[1]);
		if (i != 0)
			close(exec[i - 1].fd[0]);
		else if (i == 0 && nbr_cmd == 1)
			close(exec[i].fd[0]);
		i++;
	}
	return (0);
}

int	get_here_doc(char *delim)
{
	char	*line;
	int		len;
	int		fd[2];

	if (pipe(fd) == -1)
		//perror_exit(PIPE_ERROR);
		ft_dprintf(2, "error here_doc error");
	line = NULL;
	len = ft_strlen(delim);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!ft_strncmp(line, delim, len) && line[len] == '\n')
			break ;
		if (write(fd[1], line, ft_strlen(line)) == -1)
			ft_dprintf(2, "Error reading the here_doc");
		free(line);
	}
	free(line);
	close(fd[1]);
	return (fd[0]);
}

int	wait_all_pid(t_exec *exec, int nbr_cmd)
{
	int	i;
	int	status;

	i = 0;
	while (i < nbr_cmd)
	{
		waitpid(exec[i].pid, &status, 0);
		free(exec[i].cmd_full_path);
		i++;
	}
	free(exec);
	return (status);
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

int	execute_command(t_data **start)
{
	int		nbr_cmd;
	t_exec	*exec;
	char	**envp;
	int		i;

	nbr_cmd = nbr_of_cmd(start);
	exec = ft_calloc(nbr_cmd, sizeof(t_exec));
	if (populate_execution_table(*start, exec, nbr_cmd))
		return (1);
	print_execution_table(exec, nbr_cmd);
	envp = get_paths(&(*start)->head);
	if (!envp)
		ft_dprintf(2, "Error retrieving environment paths\n");
	get_abs_path_cmd(exec, nbr_cmd, envp);
	child_process(exec, nbr_cmd, envp);
	i = 0;
	printf("pid status : %d\n", wait_all_pid(exec, nbr_cmd));
	free_paths(envp);
	return (0);
}
