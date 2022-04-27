/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:30:35 by bterral           #+#    #+#             */
/*   Updated: 2022/04/27 16:28:13 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_cmd(t_exec	exec, char **envp)
{
	char	*cmd_path;
	char	*tmp;
	int		path_bool;
	int		i;

	
	if (access(exec.cmd[0][0], X_OK) == 0)
		return (exec.cmd[0][0]);
	i = 0;
	while (envp[i])
	{
		tmp = ft_strjoin(envp[i], "/");
		cmd_path = ft_strjoin(tmp, exec.cmd[0][0]);
		free(tmp);
		path_bool = access(cmd_path, X_OK);
		if (path_bool == 0)
			return (cmd_path);
		else
			free(cmd_path);
		i++;
	}
	if (path_bool == -1)
		perror("Command not found");
	return (cmd_path);
}

char	**get_paths(t_env **head)
{
	char	**output;
	int		i;
	t_env	*env;

	i = 0;
	env = *head;
	while (env)
	{
		if (ft_strcmp(env->name, "PATH"))
			break ;
		env = env->next;
	}
	if (env)
		output = ft_split(env->value, ':');
	else
		output = NULL;
	return (output);
}