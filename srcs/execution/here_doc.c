/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:51:56 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/13 15:36:10 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup_endl(const char *s)
{
	char	*output;
	size_t	i;

	output = (char *)malloc(sizeof(*output) * (ft_strlen(s) + 2));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\n';
	output[i + 1] = '\0';
	return (output);
}

static void	dup_buffer(char **buffer, char *line)
{
	char	*temp;

	temp = line;
	line = ft_strdup_endl(temp);
	free(temp);
	if (*buffer && buffer)
	{
		temp = ft_strdup(*buffer);
		free(*buffer);
		*buffer = ft_strjoin(temp, line);
		ft_free(&temp);
	}
	else
		*buffer = ft_strdup(line);
	free(line);
}

static void	loooop_here_doc(char **buffer, t_norm norm, int fd[2], t_env **env)
{
	char	*line;

	while (1)
	{
		norm.i = 0;
		norm.quote = NO_QUOTE;
		line = parsing_dollar(readline("> "), env, &norm.i, &norm.quote);
		if (!line)
		{
			if (*buffer)
				write(fd[1], *buffer, ft_strlen(*buffer));
			break ;
		}
		else if (ft_strcmp(line, norm.delim))
		{
			ft_free(&line);
			if (*buffer)
				write(fd[1], *buffer, ft_strlen(*buffer));
			break ;
		}
		dup_buffer(buffer, line);
	}
}

static void	child_here_doc(char *delim, int fd[2], t_env **env)
{
	char	*buffer;
	t_norm	norm;

	buffer = NULL;
	norm.delim = delim;
	loooop_here_doc(&buffer, norm, fd, env);
	exit(close(fd[1]));
}

int	get_here_doc(char *delim, t_env **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
		ft_dprintf(2, "here_doc error");
	pid = fork();
	if (pid == 0)
	{
		set_sig(&sig_handler_here);
		child_here_doc(delim, fd, env);
	}
	close(fd[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_ret_sig = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_ret_sig = WTERMSIG(status);
	return (fd[0]);
}
