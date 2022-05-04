/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:43:10 by laraujo           #+#    #+#             */
/*   Updated: 2022/05/04 11:34:09 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_var_env(char *pt)
{
	int		i;
	char	*var;

	i = 1;
	if (pt[i] == '?' || !ft_isalpha(pt[i]))
		i++;
	else
	{
		while (!is_whitespace(pt[i]) && pt[i] != '"' && pt[i] != '\'' && pt[i]
			&& pt[i] != '$' && pt[i] != '/' && ft_isalnum(pt[i]))
			i++;
	}
	var = malloc(sizeof(char) * (i + 1));
	if (!var)
		return (NULL);
	ft_strlcpy(var, pt, i + 1);
	return (var);
}

char	*join_var_env(char *line, char *var, int dollar, t_env **head)
{
	char	*end;
	char	*temp;
	char	*get_env;
	int		end_var;

	end_var = ft_strlen(var) + dollar;
	end = ft_substr(line, end_var, ft_strlen(&line[end_var]));
	ft_dprintf(1, "end=%s\n", end);
	line[dollar] = '\0';
	ft_dprintf(1, "line=%s\n", line);
	get_env = my_getenv(&var[1], head);
	if (get_env)
		temp = ft_strjoin(line, get_env);
	else
		temp = ft_strjoin(line, "");
	ft_free(&line);
	ft_dprintf(1, "temp=%s\n", temp);
	line = ft_strjoin(temp, end);
	ft_free(&end);
	ft_free(&temp);
	return (line);
}

char	*parsing_dollar(char *line, t_env **head)
{
	char	*pt;
	char	*var;
	int		i;
	int		quote;

	quote = NO_QUOTE;
	if (!line)
		return (NULL);
	pt = ft_strchr2(line, '$', &i, &quote);
	if (pt == NULL /*|| is_whitespace(pt[1])*/)
		return (line);
	var = get_var_env(pt);
	ft_dprintf(1, "var=%s\n", var);
	if (!var)
		return (NULL);
	ft_dprintf(1, "--%s, $=%d\n", var, i);
	line = join_var_env(line, var, i, head);
	ft_free(&var);
	line = parsing_dollar(line, head);
	return (line);
}
