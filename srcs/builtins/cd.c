/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:49:31 by bterral           #+#    #+#             */
/*   Updated: 2022/04/05 15:40:21 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	update_var(t_data *data, char *str, char *var)
{
	t_env	*env;

	env = NULL;
	if (ft_strcmp(var, "OLDPWD"))
	{
		ft_envdel(data, "OLDPWD");
		env = ft_env_new("OLDPWD", str);
		ft_envadd_back(&data->head, env);
		printf("OLDPWD\n");
	}
	else if (ft_strcmp(var, "PWD"))
	{
		ft_envdel(data, "PWD");
		env = ft_env_new("PWD", str);
		ft_envadd_back(&data->head, env);
		printf("PWD\n");
	}
}

static int	free_return1(char *str)
{
	free(str);
	return (1);
}

int	cd(t_data *data)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (data->str[1])
	{
		if (disable_option(data->str[1]))
			free_return1(str);
		else if (chdir(data->str[1]))
		{
			ft_dprintf(2, "cd : %s: No such file or directory\n", data->str[1]);
			free_return1(str);
		}
		else
		{
			update_var(data, str, "OLDPWD");
			free(str);
			str = getcwd(NULL, 0);
			update_var(data, str, "PWD");
			return (0);
		}
	}
	return (0);
}