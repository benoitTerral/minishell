/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:41:17 by bterral           #+#    #+#             */
/*   Updated: 2022/05/24 12:04:28 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define ERROR_FORK "minishell: fork: Resource temporarily unavailable\n"

void	initialize_pipe_structure(t_p *p_fd, int nbr_pipes)
{
	p_fd->fd_tmp = (int *)malloc(sizeof(int) * 1);
	*(p_fd->fd_tmp) = 10;
	p_fd->nbr_cmd = nbr_pipes;
}

void	close_swap_fds(int fd_0, int fd_1, int *fd_tmp)
{
	close(fd_1);
	close(*(fd_tmp));
	*fd_tmp = fd_0;
}

void	error_pid(int fd_0, int fd_1)
{
	ft_dprintf(2, RED ERROR_FORK WHITE);
	close(fd_0);
	close(fd_1);
}

void	close_in_out(int fd_in, int fd_out)
{
	if (fd_in && fd_in != -1)
		close(fd_in);
	if (fd_out && fd_out != -1)
		close(fd_out);
}
