/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:38:39 by bterral           #+#    #+#             */
/*   Updated: 2022/03/31 13:36:40 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structure.h"

int	is_build_in(t_cmd *cmd)
{
	if (ft_strcmp(cmd->str[0], "echo"))
		return (echo(cmd));
	else if (ft_strcmp(cmd->str[0], "cd"))
		return (cd(cmd));
	else if (ft_strcmp(cmd->str[0], "pwd"))
		return (pwd());
	else if (ft_strcmp(cmd->str[0], "export"))
		return (export(cmd));
	else if (ft_strcmp(cmd->str[0], "unset"))
		return (unset(cmd));
	else if (ft_strcmp(cmd->str[0], "env"))
		return (env(cmd));
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	t_cmd *cmd;
	// t_env	*print_ptr;

	(void)argc;
	(void)argv;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->head = NULL;
	init_env_var(envp, &cmd->head);
	cmd->str = ft_split_piscine("env", " \r\t");
	// cmd->token = 0;
	cmd->nb_of_arguments = ft_size_split("env", " \r\t", 0);
	is_build_in(cmd);

	printf("\n\n");

	// free(cmd);
	// cmd = (t_cmd *)malloc(sizeof(t_cmd));
	// cmd->str = ft_split_piscine("cd .. srcs", " \r\t");
	// cmd->token = 0;
	// cmd->nb_of_arguments = ft_size_split("cd .. srcs", " \r\t", 0);
	// is_build_in(cmd);

	printf("\n\n");

	// free(cmd);
	// cmd = (t_cmd *)malloc(sizeof(t_cmd));
	// cmd->str = ft_split_piscine("env", " \r\t");
	// cmd->token = 0;
	// cmd->nb_of_arguments = ft_size_split("env", " \r\t", 0);
	// is_build_in(cmd);

	free_env(&cmd->head);
	free(cmd);
	return (0);
}
