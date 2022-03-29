/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:38:39 by bterral           #+#    #+#             */
/*   Updated: 2022/03/29 14:19:48 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structure.h"

int is_build_in(t_cmd *cmd)
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

	// while (*envp)
	// {
	// 	tmp = ft_split(*envp, "=");
	// 	*envp++
	// }
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->head = NULL;
	init_env_var(envp, &cmd->head);
	cmd->str = ft_split_piscine("env", " \r\t");
	cmd->token = 0;
	cmd->nb_of_arguments = ft_size_split("env", " \r\t", 0);
	is_build_in(cmd);

	printf("\n\n");

	free(cmd);
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->str = ft_split_piscine("cd .. srcs", " \r\t");
	cmd->token = 0;
	cmd->nb_of_arguments = ft_size_split("cd .. srcs", " \r\t", 0);
	is_build_in(cmd);

	printf("\n\n");

	free(cmd);
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->str = ft_split_piscine("env", " \r\t");
	cmd->token = 0;
	cmd->nb_of_arguments = ft_size_split("env", " \r\t", 0);
	is_build_in(cmd);

	// printf("\n\n\n            ----------       ENVIRONMENT LIST START          --------------          \n\n\n");
	// print_ptr = cmd.head;
	// while (print_ptr)
	// {
	// 	printf("print_ptr.name : %s", print_ptr->name);
	// 	printf("                                                 print_ptr.value : %s\n", print_ptr->value);
	// 	print_ptr = print_ptr->next;
	// }
	// printf("\n\n\n");

	
	// printf("not handled yet\n");
	// printf("\n\n");

	// free(cmd);
	// cmd = (t_cmd *)malloc(sizeof(t_cmd));
	// cmd->str = ft_split_piscine("export", " \r\t");
	// cmd->token = 0;
	// cmd->nb_of_arguments = ft_size_split("export", " \r\t", 0);
	// is_build_in(cmd);

	// cmd->str = ft_split_piscine("export", " \r\t");
	// cmd->token = 0;
	// cmd->nb_of_arguments = ft_size_split("export", " \r\t", 0);

	// is_build_in(cmd);

	// printf("\n\n\n            ----------       ENVIRONMENT LIST START          --------------          \n\n\n");
	// print_ptr = cmd.head;
	// while (print_ptr)
	// {
	// 	printf("print_ptr.name : %s", print_ptr->name);
	// 	printf("                                                 print_ptr.value : %s\n", print_ptr->value);
	// 	print_ptr = print_ptr->next;
	// }

	return (0);
}
