/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:57:25 by laraujo           #+#    #+#             */
/*   Updated: 2022/01/18 18:04:34 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_getline(int fd, char *str)
{
	char	*temp;
	int		len_read;
	char	buf[BUFFER_SIZE + 1];

	len_read = 1;
	while (len_read > 0)
	{
		len_read = read(fd, buf, BUFFER_SIZE);
		if (len_read == -1)
			break ;
		if (len_read == 0 && str[0] != 0)
			return (str);
		buf[len_read] = '\0';
		temp = ft_strdup(str);
		free(str);
		str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(str, '\n'))
			return (str);
	}
	if (str[0] != 0)
		return (str);
	free(str);
	return (0);
}

static char	*select_l(const char *str)
{
	char	*line;
	int		i;
	int		endl;

	endl = 0;
	i = -1;
	while (str[endl] != '\n')
		endl++;
	line = malloc(sizeof(char) * (endl + 2));
	while (++i <= endl)
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

static char	*select_r(char *str, int *cpt)
{
	char	*save;
	int		i;
	int		endl;
	int		end;

	endl = 0;
	i = 0;
	while (str[endl] != '\n')
		endl++;
	end = ft_strlen(str);
	save = malloc(sizeof(char) * (end - endl));
	endl++;
	while (str[endl])
		save[i++] = str[endl++];
	save[i] = '\0';
	*cpt = -1;
	return (save);
}

char	*free_char(char **str, char **temp, int *cpt, char *line)
{
	if (*cpt == -1)
		free(*temp);
	else
	{
		free(*str);
		*str = 0;
	}
	*cpt = 1;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str = "";
	char		*line;
	char		*temp;
	static int	cpt = 0;

	if (str == 0 || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	if (!ft_strchr(str, '\n'))
	{
		temp = ft_strdup(str);
		if (cpt)
			free(str);
		str = ft_getline(fd, temp);
		if (str == 0)
			return (0);
	}
	if (ft_strchr(str, '\n'))
	{
		line = select_l(str);
		temp = str;
		str = select_r(temp, &cpt);
	}
	else
		line = ft_strdup(str);
	return (free_char(&str, &temp, &cpt, line));
}
/*
int	main()
{
	int	fd;
	char	*str = "";

	fd = open("bible", O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close(fd);
}*/
