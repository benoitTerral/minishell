/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:38:36 by bterral           #+#    #+#             */
/*   Updated: 2022/05/06 15:43:23 by laraujo          ###   ########lyon.fr   */
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

void	populate_exec_addinfo(t_exec *exec, t_data *data, int i, t_env **env)
{
	if (data->token == 2)
		exec[i].fd_in = open(data->str[1], O_RDONLY);
	else if (data->token == 4)
		exec[i].fd_out = open(data->str[1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (data->token == 5)
		exec[i].fd_out = open(data->str[1], O_CREAT | O_RDWR | O_APPEND, 0644);
	else if (data->token == 3)
		exec[i].fd_in = get_here_doc(data->str[1], env);
	if (data->token == 2)
		error_permission_files(exec[i].fd_in, data->str[1]);
	else if (data->token == 4 || data->token == 5)
		error_permission_files(exec[i].fd_out, data->str[1]);
}

int	populate_exec_table(t_data *data, t_exec *exec, int nbr_pipes, t_env **env)
{
	int	i;

	i = 0;
	while (i < nbr_pipes)
	{
		if (pipe(exec[i].fd) == -1)
			return (ft_dprintf(STDERR_FILENO, RED "pipe failed" WHITE));
		if (data->token == 1 && data->str[0])
		{
			exec[i].is_builtin = is_build_in_bool(data->str[0]);
			exec[i].cmd = &(data->str);
			exec[i].is_cmd = 1;
		}
		else
			exec[i].is_cmd = 0;
		exec[i].data = data;
		data = data->next;
		while (data && data->token != 1)
		{
			populate_exec_addinfo(exec, data, i, env);
			data = data->next;
		}
		i++;
	}
	return (0);
}

void	get_abs_path_cmd(t_exec *exec, int nbr_cmd, char **envp)
{
	int	i;

	i = 0;
	while (i < nbr_cmd)
	{
		if (!exec[i].is_builtin && exec[i].is_cmd)
			exec[i].cmd_full_path = get_cmd(exec[i], envp);
		i++;
	}
}
