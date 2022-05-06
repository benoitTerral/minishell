/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laraujo <laraujo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:30:35 by bterral           #+#    #+#             */
/*   Updated: 2022/05/06 16:41:02 by laraujo          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define ERROR_DIR "minishell: %s: No such file or directory\n"
#define ERROR_CMD_NOT "minishell: %s: command not found\n"

char	*return_err_null(char *str)
{
	ft_dprintf(2, RED ERROR_DIR WHITE, str);
	return (NULL);
}

char	*get_cmd(t_exec	exec, char **envp)
{
	char	*cmd_path;
	char	*tmp;
	int		path_bool;
	int		i;

	cmd_path = NULL;
	if (access(exec.cmd[0][0], X_OK) == 0)
		return (ft_strdup(exec.cmd[0][0]));
	i = 0;
	if (!envp)
		return (return_err_null(exec.cmd[0][0]));
	while (envp[i++])
	{
		tmp = ft_strjoin(envp[i], "/");
		cmd_path = ft_strjoin(tmp, exec.cmd[0][0]);
		free(tmp);
		path_bool = access(cmd_path, X_OK);
		if (path_bool == 0)
			return (cmd_path);
		else
			free(cmd_path);
	}
	ft_dprintf(2, RED ERROR_CMD_NOT WHITE, exec.cmd[0][0]);
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
