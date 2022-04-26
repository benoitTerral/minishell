/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:25:20 by bterral           #+#    #+#             */
/*   Updated: 2022/04/26 11:19:02 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	populate_exec(t_exec *exec, t_data **data)
{
	// if (pipe(exec->pipe.fd) == -1)
	// {
	// 	ft_dprintf(STDERR_FILENO, "pipe failed");
	// 	//free everything ??
	// }
	exec->cmd = &((*data)->str);
	printf("exec->cmd : %s\n", ((*data)->str)[0]);
	// int i;
	// i = 0;
	// while (exec->cmd[0][i])
	// {
	// 	printf("exec->cmd : %s\n", exec->cmd[0][i]);
	// 	i++;
	// }
	// (*data) = (*data)->next;
	// while ((*data) && (*data)->token != 1)
	// {
	// 	if ((*data)->token == 2)
	// 		exec->fd_in = open((*data)->str[1], O_RDONLY);
	// 	else if ((*data)->token == 4)
	// 		exec->fd_out = open((*data)->str[1], O_CREAT | O_RDWR| O_TRUNC, 0644);
	// 	else if ((*data)->token == 5)
	// 		exec->fd_out = open((*data)->str[1], O_CREAT | O_RDWR | O_APPEND, 0644);
	// 	(*data) = (*data)->next;
	// }
	(void)data;
	return (0);
}

int	child_process(t_exec *exec, int nbr_cmd, char **envp)
{
	int i;
	int	j;

	i = 0;
	while (i < nbr_cmd)
	{
		printf("fd[0] of %d: %d\n", i, exec[i].fd[0]);
		printf("fd[1]: of %d: %d\n", i, exec[i].fd[1]);
		exec[i].pid = fork();
		// if (exec[i].pid)
		// {
		// 	ft_dprintf(STDERR_FILENO, "fork failed");
		// 	return (1);
		// }
		//child process
		if (exec[i].pid == 0)
		{
			//process input
			if (exec[i].fd_in)
				dup2(exec[i].fd_in, STDIN_FILENO);
			else if (i != 0)
			{
				// dup2(exec[i].pipe.fd[0], STDIN_FILENO);
				dup2(exec[i - 1].fd[0], STDIN_FILENO);
				ft_dprintf(2, "hello %d\n", exec[i - 1].fd[0]);
			}
			close(exec[i].fd[0]);
			//process output
			if (exec[i].fd_out)
			{
				dup2(exec[i].fd_out, STDOUT_FILENO);
				ft_dprintf(2, "value of i in exec[i].fd_out: %d\n", i);
			}
			else if (i == (nbr_cmd - 1)) 
			{
				dup2(1, STDOUT_FILENO);
				ft_dprintf(2, "value of i in (i == (nbr_cmd - 1)) : %d\n", i);
			}
			else
			{
				// dup2(exec[i].pipe.fd[1], STDOUT_FILENO);
				dup2(exec[i].fd[1], STDOUT_FILENO);
				ft_dprintf(2, "hello else %d\n", i);
			}
			j = 0;
			// while (j < nbr_cmd)
			// {
			// 	// close(exec[j].pipe.fd[0]);
			// 	// close(exec[j].pipe.fd[1]);
			// 	close(exec[j].fd[0]);
			// 	close(exec[j].fd[1]);
			// 	j++;
			// }

			execve(exec[i].cmd_full_path, exec[i].cmd[0], envp);
		}
		close(exec[i].fd[1]);
		// close(exec[i].fd[1]);
		if (i != 0)
			close(exec[i - 1].fd[0]);
		else if (i == 0 && nbr_cmd == 1)
			close(exec[i].fd[0]);
		i++;
	}
	ft_dprintf(2, "finish\n");
	return (0);
}

int	execute_command(t_data **start)
{
	int		nbr_cmd;
	// int		i;
	t_exec	*exec;
	t_data	*data;
	char	**envp;


	nbr_cmd = 0;
	data = *start;
	while (data)
	{
		if (data->token == 1)
			nbr_cmd++;
		data = data->next;
	}
	exec = ft_calloc(nbr_cmd, sizeof(t_exec));


	//populate execution tables
	int	i;
	i = 0;
	data  = *start;
	while (i < nbr_cmd)
	{
		if (pipe(exec[i].fd) == -1)
		{
			ft_dprintf(STDERR_FILENO, "pipe failed");
			// free everything
		}
		exec[i].cmd = &(data->str);
		// while (exec[i].cmd[0][j])
		// {
		// 	printf("exec[i].cmd[0][j]: %s\n", exec[i].cmd[0][j]);
		// 	j++;
		// }
		data = data->next;
		while (data && data->token != 1)
		{
			printf("data token: %d\n", data->token);
			if (data->token == 2)
				exec[i].fd_in = open(data->str[1], O_RDONLY);
			else if (data->token == 4)
				exec[i].fd_out = open(data->str[1], O_CREAT | O_RDWR| O_TRUNC, 0644);
			else if (data->token == 5)
				exec[i].fd_out = open(data->str[1], O_CREAT | O_RDWR | O_APPEND, 0644);
			data = data->next;
		}
		i++;
	}

	//print tables
	printf("\n Execution table \n");
	i = 0;
	while (i < nbr_cmd)
	{
		printf("\nCommand number : %d\n", i);
		int j = 0;
		while (exec[i].cmd[0][j])
		{
			printf("exec[i].cmd[0][%d]: %s\n", j, exec[i].cmd[0][j]);
			j++;
		}
		printf("fd_in: %d\n", exec[i].fd_in);
		printf("fd_out: %d\n", exec[i].fd_out);
		i++;
	}

	// retrieve environment variables
	envp = get_paths(&(*start)->head);
	if (!envp)
		ft_dprintf(2, "Error retrieving environment paths\n");
	i = 0;
	while (envp[i])
	{
		printf("envp[%d]: %s\n", i, envp[i]);
		i++;
	}

	//Check or populate command full path
	i = 0;
	while (i < nbr_cmd)
	{
		exec[i].cmd_full_path = get_cmd(exec[i], envp);
		i++;
	}
	// print cmd_full_path
	i = 0;
	while (i < nbr_cmd)
	{
		printf("exec[%d].cmd_full_path: %s\n", i, exec[i].cmd_full_path);
		i++;
	}

	//execution of the command
	child_process(exec, nbr_cmd, envp);

	i = 0;
	while (i < nbr_cmd)
	{
		waitpid(exec[i].pid, NULL, 0);
		i++;
	}

	return (0);
}