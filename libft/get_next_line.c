/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:22:17 by bterral           #+#    #+#             */
/*   Updated: 2022/02/09 15:52:01 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line_memory(char **str)
{
	ssize_t	i;
	char	*tmp;
	char	*line;

	i = 0;
	line = NULL;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		line = ft_substr((*str), 0, (i + 1));
		tmp = ft_strdup(&(*str)[i + 1]);
		free((*str));
		(*str) = tmp;
		return (line);
	}
	else
		return (NULL);
}

static char	*store_buffer(char *buffer, char **memory)
{
	char	*tmp;

	if (*memory)
	{
		tmp = ft_strjoin(*memory, buffer);
		free(*memory);
	}
	else
		tmp = ft_strdup(buffer);
	(*memory) = tmp;
	return (NULL);
}

static char	*get_line_buffer(char *buffer, char **memory)
{
	ssize_t	i;
	char	*line;
	char	*tmp;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
	{
		if (*memory)
		{
			tmp = ft_substr(buffer, 0, (i + 1));
			line = ft_strjoin((*memory), tmp);
			free(tmp);
			free(*memory);
		}
		else
			line = ft_substr(buffer, 0, (i + 1));
		(*memory) = ft_strdup(&buffer[i + 1]);
		return (line);
	}
	else
		return (store_buffer(buffer, &(*memory)));
}

static char	*read_fd(int fd, char **str)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*output;

	output = NULL;
	while (!output)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_static(&(*str)));
		if (bytes_read == 0)
		{
			if (*str)
			{
				output = ft_strdup(*str);
				(*str) = free_static(&(*str));
			}
			return (output);
		}
		buffer[bytes_read] = '\0';
		output = get_line_buffer(buffer, &(*str));
	}
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*output;

	output = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (memory)
		output = get_line_memory(&memory);
	if (!output)
		output = read_fd(fd, &memory);
	return (output);
}
