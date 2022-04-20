/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:25:20 by bterral           #+#    #+#             */
/*   Updated: 2022/04/20 15:24:22 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int print_exec(t_exec *exec)
{
	while (exec->cmd)
	{
		printf("exec->cmd : %s\n", **(exec->cmd));
		exec->cmd++;
	}
	return (0);
}

int	populate_exec(t_exec *exec, t_data **data)
{
	if (pipe(exec->pipe->fd) == -1)
	{
		ft_dprintf(STDERR_FILENO, "pipe failed");
		//free everything ??
	}
	exec->cmd = &((*data)->str);
	(*data) = (*data)->next;
	while ((*data) && (*data)->token != 1)
	{
		if ((*data)->token == 2)
			exec->fd_in = open((*data)->str[1], O_RDONLY);
		else if ((*data)->token == 4)
			exec->fd_out = open((*data)->str[1], O_CREAT | O_RDWR| O_TRUNC, 0644);
		else if ((*data)->token == 5)
			exec->fd_out = open((*data)->str[1], O_CREAT | O_RDWR | O_APPEND, 0644);
		(*data) = (*data)->next;
	}
	return (0);
}

int	execute_command(t_data **start)
{
	int		nbr_cmd;
	int		i;
	t_exec	*exec;
	t_data	*data;

	nbr_cmd = 0;
	data = *start;
	while (data)
	{
		if (data->token == 1)
			nbr_cmd++;
		data = data->next;
	}
	exec = ft_calloc(nbr_cmd, sizeof(t_exec));
	i = 0;
	while (i < nbr_cmd)
	{
		populate_exec(&(exec[i]), &data);
		i++;
	}
	return (0);
}