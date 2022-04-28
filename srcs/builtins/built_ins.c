/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:38:39 by bterral           #+#    #+#             */
/*   Updated: 2022/04/28 11:59:30 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_build_in(t_data *data)
{
	if (ft_strcmp(data->str[0], "echo"))
		return (echo(data));
	else if (ft_strcmp(data->str[0], "cd"))
		return (cd(data));
	else if (ft_strcmp(data->str[0], "pwd"))
		return (pwd(data));
	else if (ft_strcmp(data->str[0], "export"))
		return (export(data));
	else if (ft_strcmp(data->str[0], "unset"))
		return (unset(data));
	else if (ft_strcmp(data->str[0], "env"))
		return (env(data));
	return (0);
}

int	is_build_in_bool(char *cmd)
{
	if (ft_strcmp(cmd, "echo"))
		return (1);
	else if (ft_strcmp(cmd, "cd"))
		return (1);
	else if (ft_strcmp(cmd, "pwd"))
		return (1);
	else if (ft_strcmp(cmd, "export"))
		return (1);
	else if (ft_strcmp(cmd, "unset"))
		return (1);
	else if (ft_strcmp(cmd, "env"))
		return (1);
	return (0);
}
