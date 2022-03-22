/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:43:10 by laraujo           #+#    #+#             */
/*   Updated: 2022/03/22 11:25:35 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_var_env(char *pt)
{
	int		i;
	char	*var;

	i = 1;
	while (!is_whitespace(pt[i]) && pt[i] != '"' && pt[i] != '\'' && pt[i]
		&& pt[i] != '$')
		i++;
	var = malloc(sizeof(char) * (i + 1));
	if (!var)
		return (NULL);
	ft_strlcpy(var, pt, i + 1);
	return (var);
}

char	*join_var_env(char *line, char *var, int dollar)
{
	char	*end;
	char	*temp;
	char	*get_env;
	int		end_var;

	end_var = ft_strlen(var) + dollar;
	end = ft_substr(line, end_var, ft_strlen(&line[end_var]));
	printf("end=%s\n", end);
	line[dollar] = '\0';
	printf("line=%s\n", line);
	get_env = getenv(&var[1]);
	if (get_env)
		temp = ft_strjoin(line, get_env);
	else
		temp = ft_strjoin(line, "");
	ft_free(line);
	printf("temp=%s\n", temp);
	line = ft_strjoin(temp, end);
	ft_free(end);
	ft_free(temp);
	return (line);
}

char	*parsing_dollar(char *line)
{
	char	*pt;
	char	*var;
	int		i;

	i = 0;
	pt = ft_strchr2(line, '$', &i);
	if (pt == NULL || is_whitespace(pt[1]))
		return (line);
	var = get_var_env(pt);
	printf("var=%s\n", var);
	if (!var)
		return (NULL);
	printf("--%s, $=%d\n", var, i);
	line = join_var_env(line, var, i);
	ft_free(var);
	line = parsing_dollar(line);
	return (line);
}
