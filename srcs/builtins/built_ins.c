/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:38:39 by bterral           #+#    #+#             */
/*   Updated: 2022/04/06 11:39:20 by bterral          ###   ########.fr       */
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

// int main(int argc, char **argv, char **envp)
// {
// 	t_data *data;
// 	// t_env	*print_ptr;

// 	(void)argc;
// 	(void)argv;

// 	data = (t_data *)malloc(sizeof(t_data));
// 	data->head = NULL;
	// init_env_var(envp, &data->head);
// 	data->str = ft_split_piscine("env", " \r\t");
// 	// data->token = 0;
// 	data->nb_of_arguments = ft_size_split("env", " \r\t", 0);
// 	is_build_in(data);

// 	printf("\n\n");

// 	// free(data);
// 	// data = (t_data *)malloc(sizeof(t_data));
// 	// data->str = ft_split_piscine("cd .. srcs", " \r\t");
// 	// data->token = 0;
// 	// data->nb_of_arguments = ft_size_split("cd .. srcs", " \r\t", 0);
// 	// is_build_in(data);

// 	printf("\n\n");

// 	// free(data);
// 	// data = (t_data *)malloc(sizeof(t_data));
// 	// data->str = ft_split_piscine("env", " \r\t");
// 	// data->token = 0;
// 	// data->nb_of_arguments = ft_size_split("env", " \r\t", 0);
// 	// is_build_in(data);

// 	free_env(&data->head);
// 	free(data);
// 	return (0);
// }
