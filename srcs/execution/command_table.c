/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:04:53 by bterral           #+#    #+#             */
/*   Updated: 2022/04/08 13:22:17 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int populate_command_table(t_data **start)
// {
// 	t_data		*tmp;
// 	t_cmd_info	*cmd_info;
// 	int			i;
// 	int			size;

// 	cmd_info = (t_cmd_info *)malloc(sizeof(t_cmd_info));
// 	tmp = *start;
// 	cmd_info->nbr_cmd = 0;
// 	while (tmp)
// 	{
// 		if (tmp->token == 1)
// 			cmd_info->nbr_cmd++;
// 		tmp = tmp->next;
// 	}
// 	tmp = *start;
// 	i = 0;
// 	while (i < cmd_info->nbr_cmd)
// 	{

// 		i++;
// 	}
// }

int nbr_of_commands(t_data **start)
{
	t_data	*data;
	int		nbr_cmd;
	
	nbr_cmd = 0;
	data = *start;
	while (data)
	{
		if (data->token == 1)
			nbr_cmd++;
		data = data->next;
	}
	return (nbr_cmd);
}

int	execute_command(t_data **start, char **envp)
{
	t_data	*current;
	t_data	*next;
	// int		main_infile;
	// int		main_outfile;
	// int		pipe_infile;
	// int		pipe_outfile;
	int		fd_in;
	int		fd_out;
	int		nbr_cmd;
	char	**argv;
	int		i;
	int		j;
	int		fd[2];
	pid_t	pid;

	nbr_cmd = nbr_of_commands(start);
	current = *start;
	fd_in = 0;
	fd_out = 0;
	j = 0;
	while (current)
	{
		next = current->next;
		//command and arugments
		if (current->token == 1)
		{
			argv = (char **)malloc(sizeof(char *) * (current->nbr_arg + 1));
			i = 0;
			while (i < current->nbr_arg)
			{
				argv[i] = ft_strdup(current->str[i]);
				i++;
			}
		}
		// if (next == NULL || next->token == 1)
		// {
		// 	pipe(fd);
		// 	pid = fork();
		// 	if (pid == 0)
		// 	{
		// 		if (fd_in)
		// 		{
		// 			dup2(fd_in, 0);
		// 			close(fd[0]);
		// 		}
		// 		else if (j == 0)
		// 		{
		// 			dup2(fd_in, 0);
		// 			close(fd[0]);
		// 		}
		// 		else
		// 			dup2(fd[0], 0);
		// 		if (fd_out)
		// 		{
		// 			close(fd[1]);
		// 			dup2(fd_out, 1);
		// 		}
		// 		// else if (j < nbr_cmd)
		// 		else
		// 			dup2(fd[1], 1);
		// 		close(fd[0]);
		// 		execve(argv[0], argv, envp);
		// 	}
		// 	waitpid(pid, NULL, 0);
		// 	close(fd[0]);
		// 	close(fd[1]);
		// 	printf("test\n");
		// 	j++;
		// }
		if (next == NULL || next->token == 1)
		{
			pipe(fd);
			pid = fork();
			//fonctionne en sortie
			if (pid == 0)
			{
				close(fd[0]);
				close(fd[1]);
				dup2(fd[0], 0);
				dup2(fd[1], 1);
				execve(argv[0], argv, envp);
			}
			waitpid(pid, NULL, 0);
			close(fd[0]);
			close(fd[1]);
		}
		//need to implement here_doc
		if (current->token == 2)
			fd_in = open(current->str[0], O_RDONLY);
		else if (current->token == 4)
			fd_out = open(current->str[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (current->token == 5)
			fd_out = open(current->str[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		current = current->next;
	}
	return (0);
}