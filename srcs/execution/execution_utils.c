/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:38:36 by bterral           #+#    #+#             */
/*   Updated: 2022/04/29 13:48:34 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	nbr_of_cmd(t_data **start)
{
	t_data	*data;
	int		nbr_cmd;

	data = *start;
	nbr_cmd = 0;
	while (data)
	{
		if (data->token == 1)
			nbr_cmd++;
		data = data->next;
	}
	return (nbr_cmd);
}

void	error_permission_files(int fd, char *file_name)
{
	if (fd == -1)
	{
		ft_dprintf(2, "minishell: ");
		perror(file_name);
	}
}

void	populate_exec_addinfo(t_exec *exec, t_data *data, int i)
{
	if (data->token == 2)
		exec[i].fd_in = open(data->str[1], O_RDONLY);
	else if (data->token == 4)
		exec[i].fd_out = open(data->str[1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (data->token == 5)
		exec[i].fd_out = open(data->str[1], O_CREAT | O_RDWR | O_APPEND, 0644);
	else if (data->token == 3)
		exec[i].fd_in = get_here_doc(data->str[1]);
	else if (data->token == 0)
	{
		exec[i].is_builtin = is_build_in_bool(data->str[0]);
		exec[i].data = data;
	}
	if (data->token == 2)
		error_permission_files(exec[i].fd_in, data->str[1]);
	else if (data->token == 4 || data->token == 5)
		error_permission_files(exec[i].fd_out, data->str[1]);
}

int	populate_execution_table(t_data *data, t_exec *exec, int nbr_cmd)
{
	int	i;

	i = 0;
	while (i < nbr_cmd)
	{
		if (pipe(exec[i].fd) == -1)
		{
			ft_dprintf(STDERR_FILENO, "pipe failed");
			return (1);
		}
		exec[i].cmd = &(data->str);
		data = data->next;
		while (data && data->token != 1)
		{
			populate_exec_addinfo(exec, data, i);
			data = data->next;
		}
		i++;
	}
	return (0);
}

void	print_execution_table(t_exec *exec, int nbr_cmd)
{
	int	i;
	int	j;

	i = 0;
	printf("\n Execution table \n");
	while (i < nbr_cmd)
	{
		printf("\nCommand number : %d\n", i);
		j = 0;
		while (exec[i].cmd[0][j])
		{
			printf("exec[i].cmd[0][%d]: %s\n", j, exec[i].cmd[0][j]);
			j++;
		}
		printf("fd_in: %d\n", exec[i].fd_in);
		printf("fd_out: %d\n", exec[i].fd_out);
		i++;
	}
}

void	get_abs_path_cmd(t_exec *exec, int nbr_cmd, char **envp)
{
	int	i;

	i = 0;
	while (i < nbr_cmd)
	{
		exec[i].cmd_full_path = get_cmd(exec[i], envp);
		i++;
	}
}
