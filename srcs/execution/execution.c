/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:25:20 by bterral           #+#    #+#             */
/*   Updated: 2022/04/21 14:30:22 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	populate_exec(t_exec *exec, t_data **data)
{
	if (pipe(exec->pipe.fd) == -1)
	{
		ft_dprintf(STDERR_FILENO, "pipe failed");
		//free everything ??
	}
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
		if (pipe(exec[i].pipe.fd) == -1)
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

	return (0);
}